/*	I2C For VL53L0X
 *	IN PROGRESS !!! UNTESTED !!!
 *	Last Update on August 18th, 2018
 *	Created by Reyhan
 *	Revised by Reyhan
 *	Logs :
 *	- Library imported and adjusted....
 */


#include "i2c_VL53L0X.h"

static void GPIO_setting(void);
static void I2C1_setting(void);
static void tof_setting(void);


void setup(void)
{
	GPIO_setting();
	I2C1_setting();

	DelayMs(3);
	tof_setting();

}

static void tof_setting(void)
{
	VL53L0X.address = 0x52;

//	tof_rev_id = VL53L0X_readReg(IDENTIFICATION_REVISION_ID);


//	if(!VL53L0X_init(true)) inform_error();

	VL53L0X_setTimeout(500);

	//VL53L0X_startContinuous(0);
}

static void I2C1_setting(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_I2C1, ENABLE);


	/* I2C configuration */
	I2C_InitStructure.I2C_Mode = I2C_Mode_I2C;
	I2C_InitStructure.I2C_DutyCycle = I2C_DutyCycle_2;
    //I2C_InitStructure.I2C_OwnAddress1 = 0x00;
	I2C_InitStructure.I2C_Ack = I2C_Ack_Enable;
	I2C_InitStructure.I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit;
	I2C_InitStructure.I2C_ClockSpeed = I2C_CLOCK;

	I2C_DeInit(I2C1);
	I2C_Init(I2C1, &I2C_InitStructure);
	I2C_Cmd(I2C1, ENABLE);

	//interrupt setting
	///*

	//Configure the I2C event priority
	NVIC_InitStructure.NVIC_IRQChannel = I2C1_EV_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
	//*/
}

static void GPIO_setting(void)
{
	RCC_ADCCLKConfig(RCC_PCLK2_Div2);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);

//	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE);

	//I2C
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_OD;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
}

// The Arduino two-wire interface uses a 7-bit number for the address,
// and sets the last bit correctly based on reads and writes
#define ADDRESS_DEFAULT 0b0101001

// Record the current time to check an upcoming timeout against
//#define startTimeout() (VL53L0X.timeout_start_ms = millis())
#define startTimeout() (VL53L0X.timeout_start_ms = 0)

// Check if timeout is enabled (set to nonzero value) and has expired
//#define checkTimeoutExpired() (VL53L0X.io_timeout > 0 && ((uint16_t)millis() - VL53L0X.timeout_start_ms) > VL53L0X.io_timeout)
#define checkTimeoutExpired() (0)

// Decode VCSEL (vertical cavity surface emitting laser) pulse period in PCLKs
// from register value
// based on VL53L0X_decode_vcsel_period()
#define decodeVcselPeriod(reg_val)      (((reg_val) + 1) << 1)

// Encode VCSEL pulse period register value from period in PCLKs
// based on VL53L0X_encode_vcsel_period()
#define encodeVcselPeriod(period_pclks) (((period_pclks) >> 1) - 1)

// Calculate macro period in *nanoseconds* from VCSEL period in PCLKs
// based on VL53L0X_calc_macro_period_ps()
// PLL_period_ps = 1655; macro_period_vclks = 2304
#define calcMacroPeriod(vcsel_period_pclks) ((((uint32_t)2304 * (vcsel_period_pclks) * 1655) + 500) / 1000)


static uint16_t VL53L0X_decodeTimeout(uint16_t value);
static uint16_t VL53L0X_encodeTimeout(uint16_t timeout_mclks);
static uint32_t VL53L0X_timeoutMclksToMicroseconds(uint16_t timeout_period_mclks, uint8_t vcsel_period_pclks);
static uint32_t VL53L0X_timeoutMicrosecondsToMclks(uint32_t timeout_period_us, uint8_t vcsel_period_pclks);

struct vl53l0x VL53L0X;
static uint16_t temp;


// Constructors ////////////////////////////////////////////////////////////////
/*
VL53L0X_VL53L0X(void)
  : address(ADDRESS_DEFAULT)
  , io_timeout(0) // no timeout
  , did_timeout(false)
{
}
 */
// Public Methods //////////////////////////////////////////////////////////////

void VL53L0X_setAddress(uint8_t new_addr)
{
	VL53L0X_writeReg(I2C_SLAVE_DEVICE_ADDRESS, new_addr & 0x7F);
	VL53L0X.address = new_addr;
}

// Initialize sensor using sequence based on VL53L0X_DataInit(),
// VL53L0X_StaticInit(), and VL53L0X_PerformRefCalibration().
// This function does not perform reference SPAD calibration
// (VL53L0X_PerformRefSpadManagement()), since the API user manual says that it
// is performed by ST on the bare modules; it seems like that should work well
// enough unless a cover glass is added.
// If io_2v8 (optional) is true or not given, the sensor is configured for 2V8
// mode.

bool VL53L0X_init(bool io_2v8)
{
	// VL53L0X_DataInit() begin

	// sensor uses 1V8 mode for I/O by default; switch to 2V8 mode if necessary
	if (io_2v8) {
		VL53L0X_writeReg(VHV_CONFIG_PAD_SCL_SDA__EXTSUP_HV,
				VL53L0X_readReg(VHV_CONFIG_PAD_SCL_SDA__EXTSUP_HV) | 0x01); // set bit 0
	}

	// "Set I2C standard mode"
	VL53L0X_writeReg(0x88, 0x00);

	VL53L0X_writeReg(0x80, 0x01);
	VL53L0X_writeReg(0xFF, 0x01);
	VL53L0X_writeReg(0x00, 0x00);
	VL53L0X.stop_variable = VL53L0X_readReg(0x91);
	VL53L0X_writeReg(0x00, 0x01);
	VL53L0X_writeReg(0xFF, 0x00);
	VL53L0X_writeReg(0x80, 0x00);

	// disable SIGNAL_RATE_MSRC (bit 1) and SIGNAL_RATE_PRE_RANGE (bit 4) limit checks
	VL53L0X_writeReg(MSRC_CONFIG_CONTROL, VL53L0X_readReg(MSRC_CONFIG_CONTROL) | 0x12);

	// set final range signal rate limit to 0.25 MCPS (million counts per second)
	VL53L0X_setSignalRateLimit(0.25);

	VL53L0X_writeReg(SYSTEM_SEQUENCE_CONFIG, 0xFF);

	// VL53L0X_DataInit() end

	// VL53L0X_StaticInit() begin

	uint8_t spad_count;
	bool spad_type_is_aperture;
	if (!VL53L0X_getSpadInfo(&spad_count, &spad_type_is_aperture)) {
		return false;
	}

	// The SPAD map (RefGoodSpadMap) is read by VL53L0X_get_info_from_device() in
	// the API, but the same data seems to be more easily readable from
	// GLOBAL_CONFIG_SPAD_ENABLES_REF_0 through _6, so read it from there
	uint8_t ref_spad_map[6];
	VL53L0X_readMulti(GLOBAL_CONFIG_SPAD_ENABLES_REF_0, ref_spad_map, 6);

	// -- VL53L0X_set_reference_spads() begin (assume NVM values are valid)

	VL53L0X_writeReg(0xFF, 0x01);
	VL53L0X_writeReg(DYNAMIC_SPAD_REF_EN_START_OFFSET, 0x00);
	VL53L0X_writeReg(DYNAMIC_SPAD_NUM_REQUESTED_REF_SPAD, 0x2C);
	VL53L0X_writeReg(0xFF, 0x00);
	VL53L0X_writeReg(GLOBAL_CONFIG_REF_EN_START_SELECT, 0xB4);

	uint8_t first_spad_to_enable = spad_type_is_aperture ? 12 : 0; // 12 is the first aperture spad
	uint8_t spads_enabled = 0;

	for (uint8_t i = 0; i < 48; i++) {
		if (i < first_spad_to_enable || spads_enabled == spad_count) {
			// This bit is lower than the first one that should be enabled, or
			// (reference_spad_count) bits have already been enabled, so zero this bit
			ref_spad_map[i / 8] &= ~(1 << (i % 8));
		} else if ((ref_spad_map[i / 8] >> (i % 8)) & 0x1) {
			spads_enabled++;
		}
	}

	VL53L0X_writeMulti(GLOBAL_CONFIG_SPAD_ENABLES_REF_0, ref_spad_map, 6);

	// -- VL53L0X_set_reference_spads() end

	// -- VL53L0X_load_tuning_settings() begin
	// DefaultTuningSettings from vl53l0x_tuning.h

	VL53L0X_writeReg(0xFF, 0x01);
	VL53L0X_writeReg(0x00, 0x00);

	VL53L0X_writeReg(0xFF, 0x00);
	VL53L0X_writeReg(0x09, 0x00);
	VL53L0X_writeReg(0x10, 0x00);
	VL53L0X_writeReg(0x11, 0x00);

	VL53L0X_writeReg(0x24, 0x01);
	VL53L0X_writeReg(0x25, 0xFF);
	VL53L0X_writeReg(0x75, 0x00);

	VL53L0X_writeReg(0xFF, 0x01);
	VL53L0X_writeReg(0x4E, 0x2C);
	VL53L0X_writeReg(0x48, 0x00);
	VL53L0X_writeReg(0x30, 0x20);

	VL53L0X_writeReg(0xFF, 0x00);
	VL53L0X_writeReg(0x30, 0x09);
	VL53L0X_writeReg(0x54, 0x00);
	VL53L0X_writeReg(0x31, 0x04);
	VL53L0X_writeReg(0x32, 0x03);
	VL53L0X_writeReg(0x40, 0x83);
	VL53L0X_writeReg(0x46, 0x25);
	VL53L0X_writeReg(0x60, 0x00);
	VL53L0X_writeReg(0x27, 0x00);
	VL53L0X_writeReg(0x50, 0x06);
	VL53L0X_writeReg(0x51, 0x00);
	VL53L0X_writeReg(0x52, 0x96);
	VL53L0X_writeReg(0x56, 0x08);
	VL53L0X_writeReg(0x57, 0x30);
	VL53L0X_writeReg(0x61, 0x00);
	VL53L0X_writeReg(0x62, 0x00);
	VL53L0X_writeReg(0x64, 0x00);
	VL53L0X_writeReg(0x65, 0x00);
	VL53L0X_writeReg(0x66, 0xA0);

	VL53L0X_writeReg(0xFF, 0x01);
	VL53L0X_writeReg(0x22, 0x32);
	VL53L0X_writeReg(0x47, 0x14);
	VL53L0X_writeReg(0x49, 0xFF);
	VL53L0X_writeReg(0x4A, 0x00);

	VL53L0X_writeReg(0xFF, 0x00);
	VL53L0X_writeReg(0x7A, 0x0A);
	VL53L0X_writeReg(0x7B, 0x00);
	VL53L0X_writeReg(0x78, 0x21);

	VL53L0X_writeReg(0xFF, 0x01);
	VL53L0X_writeReg(0x23, 0x34);
	VL53L0X_writeReg(0x42, 0x00);
	VL53L0X_writeReg(0x44, 0xFF);
	VL53L0X_writeReg(0x45, 0x26);
	VL53L0X_writeReg(0x46, 0x05);
	VL53L0X_writeReg(0x40, 0x40);
	VL53L0X_writeReg(0x0E, 0x06);
	VL53L0X_writeReg(0x20, 0x1A);
	VL53L0X_writeReg(0x43, 0x40);

	VL53L0X_writeReg(0xFF, 0x00);
	VL53L0X_writeReg(0x34, 0x03);
	VL53L0X_writeReg(0x35, 0x44);

	VL53L0X_writeReg(0xFF, 0x01);
	VL53L0X_writeReg(0x31, 0x04);
	VL53L0X_writeReg(0x4B, 0x09);
	VL53L0X_writeReg(0x4C, 0x05);
	VL53L0X_writeReg(0x4D, 0x04);

	VL53L0X_writeReg(0xFF, 0x00);
	VL53L0X_writeReg(0x44, 0x00);
	VL53L0X_writeReg(0x45, 0x20);
	VL53L0X_writeReg(0x47, 0x08);
	VL53L0X_writeReg(0x48, 0x28);
	VL53L0X_writeReg(0x67, 0x00);
	VL53L0X_writeReg(0x70, 0x04);
	VL53L0X_writeReg(0x71, 0x01);
	VL53L0X_writeReg(0x72, 0xFE);
	VL53L0X_writeReg(0x76, 0x00);
	VL53L0X_writeReg(0x77, 0x00);

	VL53L0X_writeReg(0xFF, 0x01);
	VL53L0X_writeReg(0x0D, 0x01);

	VL53L0X_writeReg(0xFF, 0x00);
	VL53L0X_writeReg(0x80, 0x01);
	VL53L0X_writeReg(0x01, 0xF8);

	VL53L0X_writeReg(0xFF, 0x01);
	VL53L0X_writeReg(0x8E, 0x01);
	VL53L0X_writeReg(0x00, 0x01);
	VL53L0X_writeReg(0xFF, 0x00);
	VL53L0X_writeReg(0x80, 0x00);

	// -- VL53L0X_load_tuning_settings() end

	// "Set interrupt config to new sample ready"
	// -- VL53L0X_SetGpioConfig() begin

	VL53L0X_writeReg(SYSTEM_INTERRUPT_CONFIG_GPIO, 0x04);
	VL53L0X_writeReg(GPIO_HV_MUX_ACTIVE_HIGH, (uint8_t) (VL53L0X_readReg(GPIO_HV_MUX_ACTIVE_HIGH) & ~0x10)); // active low
	VL53L0X_writeReg(SYSTEM_INTERRUPT_CLEAR, 0x01);

	// -- VL53L0X_SetGpioConfig() end

	VL53L0X.measurement_timing_budget_us = VL53L0X_getMeasurementTimingBudget();

	// "Disable MSRC and TCC by default"
	// MSRC = Minimum Signal Rate Check
	// TCC = Target CentreCheck
	// -- VL53L0X_SetSequenceStepEnable() begin

	VL53L0X_writeReg(SYSTEM_SEQUENCE_CONFIG, 0xE8);

	// -- VL53L0X_SetSequenceStepEnable() end

	// "Recalculate timing budget"
	VL53L0X_setMeasurementTimingBudget(VL53L0X.measurement_timing_budget_us);

	// VL53L0X_StaticInit() end

	// VL53L0X_PerformRefCalibration() begin (VL53L0X_perform_ref_calibration())

	// -- VL53L0X_perform_vhv_calibration() begin

	VL53L0X_writeReg(SYSTEM_SEQUENCE_CONFIG, 0x01);
	if (!VL53L0X_performSingleRefCalibration(0x40)) {
		return false;
	}

	// -- VL53L0X_perform_vhv_calibration() end

	// -- VL53L0X_perform_phase_calibration() begin

	VL53L0X_writeReg(SYSTEM_SEQUENCE_CONFIG, 0x02);
	if (!VL53L0X_performSingleRefCalibration(0x00)) {
		return false;
	}

	// -- VL53L0X_perform_phase_calibration() end

	// "restore the previous Sequence Config"
	VL53L0X_writeReg(SYSTEM_SEQUENCE_CONFIG, 0xE8);

	// VL53L0X_PerformRefCalibration() end

	return true;
}

// Write an 8-bit register

void VL53L0X_writeReg(uint8_t reg, uint8_t value)
{
	//while (I2C_GetFlagStatus(I2C1, I2C_FLAG_BUSY));
	I2C_GenerateSTART(I2C1, ENABLE);
	while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_MODE_SELECT));
	I2C_Send7bitAddress(I2C1, VL53L0X.address, I2C_Direction_Transmitter);
	while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED));
	I2C_SendData(I2C1, reg);
	while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTED));
	I2C_SendData(I2C1, value);
	while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTED));

	//last_status = Wire.endTransmission();  //what??
	I2C_GenerateSTOP(I2C1, ENABLE);
	while (I2C_GetFlagStatus(I2C1, I2C_FLAG_STOPF));
}

// Write a 16-bit register

void VL53L0X_writeReg16Bit(uint8_t reg, uint16_t value)
{
	while (I2C_GetFlagStatus(I2C1, I2C_FLAG_BUSY));
	I2C_GenerateSTART(I2C1, ENABLE);
	while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_MODE_SELECT));
	I2C_Send7bitAddress(I2C1, VL53L0X.address, I2C_Direction_Transmitter);
	while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED));
	I2C_SendData(I2C1, reg);
	while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTED));

	for (size_t i = 2; i > 0; i--) {
		I2C_SendData(I2C1, (uint8_t) (value >> (i - 1)) & 0xFF);
		while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTED));
	}

	//last_status = Wire.endTransmission(); //what??
	I2C_GenerateSTOP(I2C1, ENABLE);
	while (I2C_GetFlagStatus(I2C1, I2C_FLAG_STOPF));

}

// Write a 32-bit register

void VL53L0X_writeReg32Bit(uint8_t reg, uint32_t value)
{
	while (I2C_GetFlagStatus(I2C1, I2C_FLAG_BUSY));
	I2C_GenerateSTART(I2C1, ENABLE);
	while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_MODE_SELECT));
	I2C_Send7bitAddress(I2C1, VL53L0X.address, I2C_Direction_Transmitter);
	while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED));
	I2C_SendData(I2C1, reg);
	while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTED));

	for (size_t i = 4; i > 0; i--) {
		I2C_SendData(I2C1, (uint8_t) (value >> (i - 1)) & 0xFF);
		while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTED));
	}

	//last_status = Wire.endTransmission();
	I2C_GenerateSTOP(I2C1, ENABLE);
	while (I2C_GetFlagStatus(I2C1, I2C_FLAG_STOPF));
}

// Read an 8-bit register

uint8_t VL53L0X_readReg(uint8_t reg)
{
	while (I2C_GetFlagStatus(I2C1, I2C_FLAG_BUSY));
	I2C_GenerateSTART(I2C1, ENABLE);
	while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_MODE_SELECT));
	I2C_Send7bitAddress(I2C1, VL53L0X.address, I2C_Direction_Transmitter);
	while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED));
	I2C_SendData(I2C1, reg);
	while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTED));
	I2C_GenerateSTOP(I2C1, ENABLE);
	while (I2C_GetFlagStatus(I2C1, I2C_FLAG_STOPF));

	while (I2C_GetFlagStatus(I2C1, I2C_FLAG_BUSY));
	I2C_GenerateSTART(I2C1, ENABLE);
	while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_MODE_SELECT));
	I2C_Send7bitAddress(I2C1, VL53L0X.address, I2C_Direction_Receiver);
	while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_RECEIVER_MODE_SELECTED));
	I2C_AcknowledgeConfig(I2C1, DISABLE);
	while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_RECEIVED));
	uint8_t value = I2C_ReceiveData(I2C1);
	temp = I2C1->SR2;
	I2C_GenerateSTOP(I2C1, ENABLE);
	while (I2C_GetFlagStatus(I2C1, I2C_FLAG_STOPF));
	I2C_AcknowledgeConfig(I2C1, ENABLE);

//	if (I2C_GetFlagStatus(I2C1, I2C_FLAG_BERR))

	return value;
}

// Read a 16-bit register

uint16_t VL53L0X_readReg16Bit(uint8_t reg)
{
	while (I2C_GetFlagStatus(I2C1, I2C_FLAG_BUSY));
	I2C_GenerateSTART(I2C1, ENABLE);
	while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_MODE_SELECT));
	I2C_Send7bitAddress(I2C1, VL53L0X.address, I2C_Direction_Transmitter);
	while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED));
	I2C_SendData(I2C1, reg);
	while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTED));
	//last_status = Wire.endTransmission();
	I2C_GenerateSTOP(I2C1, ENABLE);
	while (I2C_GetFlagStatus(I2C1, I2C_FLAG_STOPF));

	while (I2C_GetFlagStatus(I2C1, I2C_FLAG_BUSY));
	I2C_GenerateSTART(I2C1, ENABLE);
	while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_MODE_SELECT));
	I2C_Send7bitAddress(I2C1, VL53L0X.address, I2C_Direction_Receiver);
	while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_RECEIVER_MODE_SELECTED));

	uint16_t value = 0;
	for (size_t i = 2; i > 0; i--) {
		if (i == 1) {
			I2C_AcknowledgeConfig(I2C1, DISABLE);
		}
		while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_RECEIVED));
		value |= (uint16_t) (I2C_ReceiveData(I2C1) << (8 * (i - 1)));
	}
	temp = I2C1->SR2;
	I2C_GenerateSTOP(I2C1, ENABLE);
	while (I2C_GetFlagStatus(I2C1, I2C_FLAG_STOPF));
	I2C_AcknowledgeConfig(I2C1, ENABLE);

	return value;
}

// Read a 32-bit register

uint32_t VL53L0X_readReg32Bit(uint8_t reg)
{
	while (I2C_GetFlagStatus(I2C1, I2C_FLAG_BUSY));
	I2C_GenerateSTART(I2C1, ENABLE);
	while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_MODE_SELECT));
	I2C_Send7bitAddress(I2C1, VL53L0X.address, I2C_Direction_Transmitter);
	while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED));
	I2C_SendData(I2C1, reg);
	while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTED));
	//last_status = Wire.endTransmission();
	I2C_GenerateSTOP(I2C1, ENABLE);
	while (I2C_GetFlagStatus(I2C1, I2C_FLAG_STOPF));


	while (I2C_GetFlagStatus(I2C1, I2C_FLAG_BUSY));
	I2C_GenerateSTART(I2C1, ENABLE);
	while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_MODE_SELECT));
	I2C_Send7bitAddress(I2C1, VL53L0X.address, I2C_Direction_Receiver);
	while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_RECEIVER_MODE_SELECTED));

	uint32_t value = 0;
	for (size_t i = 4; i > 0; i--) {
		if (i == 1) {
			I2C_AcknowledgeConfig(I2C1, DISABLE);
		}
		while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_RECEIVED));
		value |= (uint32_t) (I2C_ReceiveData(I2C1) << (8 * (i - 1)));
	}
	//temp = I2C1->SR2;
	I2C_GenerateSTOP(I2C1, ENABLE);
	while (I2C_GetFlagStatus(I2C1, I2C_FLAG_STOPF));
	I2C_AcknowledgeConfig(I2C1, ENABLE);

	return value;
}

// Write an arbitrary number of bytes from the given array to the sensor,
// starting at the given register

void VL53L0X_writeMulti(uint8_t reg, uint8_t const * src, uint8_t count)
{
	while (I2C_GetFlagStatus(I2C1, I2C_FLAG_BUSY));
	I2C_GenerateSTART(I2C1, ENABLE);
	while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_MODE_SELECT));
	I2C_Send7bitAddress(I2C1, VL53L0X.address, I2C_Direction_Transmitter);
	while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED));
	I2C_SendData(I2C1, reg);
	while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTED));

	while (count-- > 0) {
		I2C_SendData(I2C1, *(src++));
		while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTED));
	}

	//last_status = Wire.endTransmission();
	I2C_GenerateSTOP(I2C1, ENABLE);
	while (I2C_GetFlagStatus(I2C1, I2C_FLAG_STOPF));
}

// Read an arbitrary number of bytes from the sensor, starting at the given
// register, into the given array

void VL53L0X_readMulti(uint8_t reg, uint8_t * dst, uint8_t count)
{
	while (I2C_GetFlagStatus(I2C1, I2C_FLAG_BUSY));
	I2C_GenerateSTART(I2C1, ENABLE);
	while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_MODE_SELECT));
	I2C_Send7bitAddress(I2C1, VL53L0X.address, I2C_Direction_Transmitter);
	while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED));
	I2C_SendData(I2C1, reg);
	while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTED));
	//last_status = Wire.endTransmission();
	I2C_GenerateSTOP(I2C1, ENABLE);
	while (I2C_GetFlagStatus(I2C1, I2C_FLAG_STOPF));

	//Wire.requestFrom(VL53L0X.address, count);	//what's?
	I2C_GenerateSTART(I2C1, ENABLE);
	while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_MODE_SELECT));
	I2C_Send7bitAddress(I2C1, VL53L0X.address, I2C_Direction_Receiver);
	while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_RECEIVER_MODE_SELECTED));

	while (count-- > 0) {
		if (count == 1) {
			I2C_AcknowledgeConfig(I2C1, DISABLE);
		}
		while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_RECEIVED));
		*(dst++) = I2C_ReceiveData(I2C1);
	}
	while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_RECEIVED));
	temp = I2C1->SR2;
	I2C_GenerateSTOP(I2C1, ENABLE);
	while (I2C_GetFlagStatus(I2C1, I2C_FLAG_STOPF));
	I2C_AcknowledgeConfig(I2C1, ENABLE);
}

// Set the return signal rate limit check value in units of MCPS (mega counts
// per second). "This represents the amplitude of the signal reflected from the
// target and detected by the device"; setting this limit presumably determines
// the minimum measurement necessary for the sensor to report a valid reading.
// Setting a lower limit increases the potential range of the sensor but also
// seems to increase the likelihood of getting an inaccurate reading because of
// unwanted reflections from objects other than the intended target.
// Defaults to 0.25 MCPS as initialized by the ST API and this library.

bool VL53L0X_setSignalRateLimit(float limit_Mcps)
{
	if (limit_Mcps < 0 || limit_Mcps > 511.99) {
		return false;
	}

	// Q9.7 fixed point format (9 integer bits, 7 fractional bits)
	VL53L0X_writeReg16Bit(FINAL_RANGE_CONFIG_MIN_COUNT_RATE_RTN_LIMIT, (uint16_t) (limit_Mcps * (1 << 7)));
	return true;
}

// Get the return signal rate limit check value in MCPS

float VL53L0X_getSignalRateLimit(void)
{
	return(float) VL53L0X_readReg16Bit(FINAL_RANGE_CONFIG_MIN_COUNT_RATE_RTN_LIMIT) / (1 << 7);
}

// Set the measurement timing budget in microseconds, which is the time allowed
// for one measurement; the ST API and this library take care of splitting the
// timing budget among the sub-steps in the ranging sequence. A longer timing
// budget allows for more accurate measurements. Increasing the budget by a
// factor of N decreases the range measurement standard deviation by a factor of
// sqrt(N). Defaults to about 33 milliseconds; the minimum is 20 ms.
// based on VL53L0X_set_measurement_timing_budget_micro_seconds()

bool VL53L0X_setMeasurementTimingBudget(uint32_t budget_us)
{
	struct SequenceStepEnables enables;
	struct SequenceStepTimeouts timeouts;

	uint16_t const StartOverhead = 1320; // note that this is different than the value in get_
	uint16_t const EndOverhead = 960;
	uint16_t const MsrcOverhead = 660;
	uint16_t const TccOverhead = 590;
	uint16_t const DssOverhead = 690;
	uint16_t const PreRangeOverhead = 660;
	uint16_t const FinalRangeOverhead = 550;

	uint32_t const MinTimingBudget = 20000;

	if (budget_us < MinTimingBudget) {
		return false;
	}

	uint32_t used_budget_us = (uint32_t) (StartOverhead + EndOverhead);

	VL53L0X_getSequenceStepEnables(&enables);
	VL53L0X_getSequenceStepTimeouts(&enables, &timeouts);

	if (enables.tcc) {
		used_budget_us += (timeouts.msrc_dss_tcc_us + TccOverhead);
	}

	if (enables.dss) {
		used_budget_us += 2 * (timeouts.msrc_dss_tcc_us + DssOverhead);
	} else if (enables.msrc) {
		used_budget_us += (timeouts.msrc_dss_tcc_us + MsrcOverhead);
	}

	if (enables.pre_range) {
		used_budget_us += (timeouts.pre_range_us + PreRangeOverhead);
	}

	if (enables.final_range) {
		used_budget_us += FinalRangeOverhead;

		// "Note that the final range timeout is determined by the timing
		// budget and the sum of all other timeouts within the sequence.
		// If there is no room for the final range timeout, then an error
		// will be set. Otherwise the remaining time will be applied to
		// the final range."

		if (used_budget_us > budget_us) {
			// "Requested timeout too big."
			return false;
		}

		uint32_t final_range_timeout_us = budget_us - used_budget_us;

		// set_sequence_step_timeout() begin
		// (SequenceStepId == VL53L0X_SEQUENCESTEP_FINAL_RANGE)

		// "For the final range timeout, the pre-range timeout
		//  must be added. To do this both final and pre-range
		//  timeouts must be expressed in macro periods MClks
		//  because they have different vcsel periods."

		uint16_t final_range_timeout_mclks = (uint16_t)
				VL53L0X_timeoutMicrosecondsToMclks(final_range_timeout_us,
				(uint8_t) timeouts.final_range_vcsel_period_pclks);

		if (enables.pre_range) {
			final_range_timeout_mclks += (uint16_t) timeouts.pre_range_mclks;
		}

		VL53L0X_writeReg16Bit(FINAL_RANGE_CONFIG_TIMEOUT_MACROP_HI,
				VL53L0X_encodeTimeout(final_range_timeout_mclks));

		// set_sequence_step_timeout() end

		VL53L0X.measurement_timing_budget_us = budget_us; // store for internal reuse
	}
	return true;
}

// Get the measurement timing budget in microseconds
// based on VL53L0X_get_measurement_timing_budget_micro_seconds()
// in us

uint32_t VL53L0X_getMeasurementTimingBudget(void)
{
	struct SequenceStepEnables enables;
	struct SequenceStepTimeouts timeouts;

	uint16_t const StartOverhead = 1910; // note that this is different than the value in set_
	uint16_t const EndOverhead = 960;
	uint16_t const MsrcOverhead = 660;
	uint16_t const TccOverhead = 590;
	uint16_t const DssOverhead = 690;
	uint16_t const PreRangeOverhead = 660;
	uint16_t const FinalRangeOverhead = 550;

	// "Start and end overhead times always present"
	uint32_t budget_us = (uint32_t) (StartOverhead + EndOverhead);

	VL53L0X_getSequenceStepEnables(&enables);
	VL53L0X_getSequenceStepTimeouts(&enables, &timeouts);

	if (enables.tcc) {
		budget_us += (timeouts.msrc_dss_tcc_us + TccOverhead);
	}

	if (enables.dss) {
		budget_us += 2 * (timeouts.msrc_dss_tcc_us + DssOverhead);
	} else if (enables.msrc) {
		budget_us += (timeouts.msrc_dss_tcc_us + MsrcOverhead);
	}

	if (enables.pre_range) {
		budget_us += (timeouts.pre_range_us + PreRangeOverhead);
	}

	if (enables.final_range) {
		budget_us += (timeouts.final_range_us + FinalRangeOverhead);
	}

	VL53L0X.measurement_timing_budget_us = budget_us; // store for internal reuse
	return budget_us;
}

// Set the VCSEL (vertical cavity surface emitting laser) pulse period for the
// given period type (pre-range or final range) to the given value in PCLKs.
// Longer periods seem to increase the potential range of the sensor.
// Valid values are (even numbers only):
//  pre:  12 to 18 (initialized default: 14)
//  final: 8 to 14 (initialized default: 10)
// based on VL53L0X_set_vcsel_pulse_period()

bool VL53L0X_setVcselPulsePeriod(enum vcselPeriodType type, uint8_t period_pclks)
{
	uint8_t vcsel_period_reg = (uint8_t) encodeVcselPeriod(period_pclks);

	struct SequenceStepEnables enables;
	struct SequenceStepTimeouts timeouts;

	VL53L0X_getSequenceStepEnables(&enables);
	VL53L0X_getSequenceStepTimeouts(&enables, &timeouts);

	// "Apply specific settings for the requested clock period"
	// "Re-calculate and apply timeouts, in macro periods"

	// "When the VCSEL period for the pre or final range is changed,
	// the corresponding timeout must be read from the device using
	// the current VCSEL period, then the new VCSEL period can be
	// applied. The timeout then must be written back to the device
	// using the new VCSEL period.
	//
	// For the MSRC timeout, the same applies - this timeout being
	// dependant on the pre-range vcsel period."


	if (type == VcselPeriodPreRange) {
		// "Set phase check limits"
		switch (period_pclks) {
		case 12:
			VL53L0X_writeReg(PRE_RANGE_CONFIG_VALID_PHASE_HIGH, 0x18);
			break;

		case 14:
			VL53L0X_writeReg(PRE_RANGE_CONFIG_VALID_PHASE_HIGH, 0x30);
			break;

		case 16:
			VL53L0X_writeReg(PRE_RANGE_CONFIG_VALID_PHASE_HIGH, 0x40);
			break;

		case 18:
			VL53L0X_writeReg(PRE_RANGE_CONFIG_VALID_PHASE_HIGH, 0x50);
			break;

		default:
			// invalid period
			return false;
		}
		VL53L0X_writeReg(PRE_RANGE_CONFIG_VALID_PHASE_LOW, 0x08);

		// apply new VCSEL period
		VL53L0X_writeReg(PRE_RANGE_CONFIG_VCSEL_PERIOD, vcsel_period_reg);

		// update timeouts

		// set_sequence_step_timeout() begin
		// (SequenceStepId == VL53L0X_SEQUENCESTEP_PRE_RANGE)

		uint16_t new_pre_range_timeout_mclks = (uint16_t)
				VL53L0X_timeoutMicrosecondsToMclks(timeouts.pre_range_us, period_pclks);

		VL53L0X_writeReg16Bit(PRE_RANGE_CONFIG_TIMEOUT_MACROP_HI,
				VL53L0X_encodeTimeout(new_pre_range_timeout_mclks));

		// set_sequence_step_timeout() end

		// set_sequence_step_timeout() begin
		// (SequenceStepId == VL53L0X_SEQUENCESTEP_MSRC)

		uint16_t new_msrc_timeout_mclks = (uint16_t)
				VL53L0X_timeoutMicrosecondsToMclks(timeouts.msrc_dss_tcc_us, period_pclks);

		VL53L0X_writeReg(MSRC_CONFIG_TIMEOUT_MACROP,
				(new_msrc_timeout_mclks > 256) ? 255 : (new_msrc_timeout_mclks - 1));

		// set_sequence_step_timeout() end
	} else if (type == VcselPeriodFinalRange) {
		switch (period_pclks) {
		case 8:
			VL53L0X_writeReg(FINAL_RANGE_CONFIG_VALID_PHASE_HIGH, 0x10);
			VL53L0X_writeReg(FINAL_RANGE_CONFIG_VALID_PHASE_LOW, 0x08);
			VL53L0X_writeReg(GLOBAL_CONFIG_VCSEL_WIDTH, 0x02);
			VL53L0X_writeReg(ALGO_PHASECAL_CONFIG_TIMEOUT, 0x0C);
			VL53L0X_writeReg(0xFF, 0x01);
			VL53L0X_writeReg(ALGO_PHASECAL_LIM, 0x30);
			VL53L0X_writeReg(0xFF, 0x00);
			break;

		case 10:
			VL53L0X_writeReg(FINAL_RANGE_CONFIG_VALID_PHASE_HIGH, 0x28);
			VL53L0X_writeReg(FINAL_RANGE_CONFIG_VALID_PHASE_LOW, 0x08);
			VL53L0X_writeReg(GLOBAL_CONFIG_VCSEL_WIDTH, 0x03);
			VL53L0X_writeReg(ALGO_PHASECAL_CONFIG_TIMEOUT, 0x09);
			VL53L0X_writeReg(0xFF, 0x01);
			VL53L0X_writeReg(ALGO_PHASECAL_LIM, 0x20);
			VL53L0X_writeReg(0xFF, 0x00);
			break;

		case 12:
			VL53L0X_writeReg(FINAL_RANGE_CONFIG_VALID_PHASE_HIGH, 0x38);
			VL53L0X_writeReg(FINAL_RANGE_CONFIG_VALID_PHASE_LOW, 0x08);
			VL53L0X_writeReg(GLOBAL_CONFIG_VCSEL_WIDTH, 0x03);
			VL53L0X_writeReg(ALGO_PHASECAL_CONFIG_TIMEOUT, 0x08);
			VL53L0X_writeReg(0xFF, 0x01);
			VL53L0X_writeReg(ALGO_PHASECAL_LIM, 0x20);
			VL53L0X_writeReg(0xFF, 0x00);
			break;

		case 14:
			VL53L0X_writeReg(FINAL_RANGE_CONFIG_VALID_PHASE_HIGH, 0x48);
			VL53L0X_writeReg(FINAL_RANGE_CONFIG_VALID_PHASE_LOW, 0x08);
			VL53L0X_writeReg(GLOBAL_CONFIG_VCSEL_WIDTH, 0x03);
			VL53L0X_writeReg(ALGO_PHASECAL_CONFIG_TIMEOUT, 0x07);
			VL53L0X_writeReg(0xFF, 0x01);
			VL53L0X_writeReg(ALGO_PHASECAL_LIM, 0x20);
			VL53L0X_writeReg(0xFF, 0x00);
			break;

		default:
			// invalid period
			return false;
		}

		// apply new VCSEL period
		VL53L0X_writeReg(FINAL_RANGE_CONFIG_VCSEL_PERIOD, vcsel_period_reg);

		// update timeouts

		// set_sequence_step_timeout() begin
		// (SequenceStepId == VL53L0X_SEQUENCESTEP_FINAL_RANGE)

		// "For the final range timeout, the pre-range timeout
		//  must be added. To do this both final and pre-range
		//  timeouts must be expressed in macro periods MClks
		//  because they have different vcsel periods."

		uint16_t new_final_range_timeout_mclks =
				VL53L0X_timeoutMicrosecondsToMclks(timeouts.final_range_us, period_pclks);

		if (enables.pre_range) {
			new_final_range_timeout_mclks += timeouts.pre_range_mclks;
		}

		VL53L0X_writeReg16Bit(FINAL_RANGE_CONFIG_TIMEOUT_MACROP_HI,
				VL53L0X_encodeTimeout(new_final_range_timeout_mclks));

		// set_sequence_step_timeout end
	} else {
		// invalid type
		return false;
	}

	// "Finally, the timing budget must be re-applied"

	VL53L0X_setMeasurementTimingBudget(VL53L0X.measurement_timing_budget_us);

	// "Perform the phase calibration. This is needed after changing on vcsel period."
	// VL53L0X_perform_phase_calibration() begin

	uint8_t sequence_config = VL53L0X_readReg(SYSTEM_SEQUENCE_CONFIG);
	VL53L0X_writeReg(SYSTEM_SEQUENCE_CONFIG, 0x02);
	VL53L0X_performSingleRefCalibration(0x0);
	VL53L0X_writeReg(SYSTEM_SEQUENCE_CONFIG, sequence_config);

	// VL53L0X_perform_phase_calibration() end

	return true;
}

// Get the VCSEL pulse period in PCLKs for the given period type.
// based on VL53L0X_get_vcsel_pulse_period()

uint16_t VL53L0X_getVcselPulsePeriod(enum vcselPeriodType type)
{
	if (type == VcselPeriodPreRange) {
		return decodeVcselPeriod(VL53L0X_readReg(PRE_RANGE_CONFIG_VCSEL_PERIOD));
	} else if (type == VcselPeriodFinalRange) {
		return decodeVcselPeriod(VL53L0X_readReg(FINAL_RANGE_CONFIG_VCSEL_PERIOD));
	} else {
		return 255;
	}
}

// Start continuous ranging measurements. If period_ms (optional) is 0 or not
// given, continuous back-to-back mode is used (the sensor takes measurements as
// often as possible); otherwise, continuous timed mode is used, with the given
// inter-measurement period in milliseconds determining how often the sensor
// takes a measurement.
// based on VL53L0X_StartMeasurement()

void VL53L0X_startContinuous(uint32_t period_ms)
{
	VL53L0X_writeReg(0x80, 0x01);
	VL53L0X_writeReg(0xFF, 0x01);
	VL53L0X_writeReg(0x00, 0x00);
	VL53L0X_writeReg(0x91, VL53L0X.stop_variable);
	VL53L0X_writeReg(0x00, 0x01);
	VL53L0X_writeReg(0xFF, 0x00);
	VL53L0X_writeReg(0x80, 0x00);

	if (period_ms != 0) {
		// continuous timed mode

		// VL53L0X_SetInterMeasurementPeriodMilliSeconds() begin

		uint16_t osc_calibrate_val = VL53L0X_readReg16Bit(OSC_CALIBRATE_VAL);

		if (osc_calibrate_val != 0) {
			period_ms *= osc_calibrate_val;
		}

		VL53L0X_writeReg32Bit(SYSTEM_INTERMEASUREMENT_PERIOD, period_ms);

		// VL53L0X_SetInterMeasurementPeriodMilliSeconds() end

		VL53L0X_writeReg(SYSRANGE_START, 0x04); // VL53L0X_REG_SYSRANGE_MODE_TIMED
	} else {
		// continuous back-to-back mode
		VL53L0X_writeReg(SYSRANGE_START, 0x02); // VL53L0X_REG_SYSRANGE_MODE_BACKTOBACK
	}
}

// Stop continuous measurements
// based on VL53L0X_StopMeasurement()

void VL53L0X_stopContinuous(void)
{
	VL53L0X_writeReg(SYSRANGE_START, 0x01); // VL53L0X_REG_SYSRANGE_MODE_SINGLESHOT

	VL53L0X_writeReg(0xFF, 0x01);
	VL53L0X_writeReg(0x00, 0x00);
	VL53L0X_writeReg(0x91, 0x00);
	VL53L0X_writeReg(0x00, 0x01);
	VL53L0X_writeReg(0xFF, 0x00);
}

// Returns a range reading in millimeters when continuous mode is active
// (readRangeSingleMillimeters() also calls this function after starting a
// single-shot range measurement)

uint16_t VL53L0X_readRangeContinuousMillimeters(void)
{
	startTimeout();
	while ((VL53L0X_readReg(RESULT_INTERRUPT_STATUS) & 0x07) == 0) {
		if (checkTimeoutExpired()) {
			VL53L0X.did_timeout = true;
			return 65535;
		}
	}

	// assumptions: Linearity Corrective Gain is 1000 (default);
	// fractional ranging is not enabled
	uint16_t range = VL53L0X_readReg16Bit(RESULT_RANGE_STATUS + 10);

	VL53L0X_writeReg(SYSTEM_INTERRUPT_CLEAR, 0x01);

	return range;
}

// Performs a single-shot range measurement and returns the reading in
// millimeters
// based on VL53L0X_PerformSingleRangingMeasurement()

uint16_t VL53L0X_readRangeSingleMillimeters(void)
{
	VL53L0X_writeReg(0x80, 0x01);
	VL53L0X_writeReg(0xFF, 0x01);
	VL53L0X_writeReg(0x00, 0x00);
	VL53L0X_writeReg(0x91, VL53L0X.stop_variable);
	VL53L0X_writeReg(0x00, 0x01);
	VL53L0X_writeReg(0xFF, 0x00);
	VL53L0X_writeReg(0x80, 0x00);

	VL53L0X_writeReg(SYSRANGE_START, 0x01);

	// "Wait until start bit has been cleared"
	startTimeout();
	while (VL53L0X_readReg(SYSRANGE_START) & 0x01) {
		if (checkTimeoutExpired()) {
			VL53L0X.did_timeout = true;
			return 65535;
		}
	}

	return VL53L0X_readRangeContinuousMillimeters();
}

// Did a timeout occur in one of the read functions since the last call to
// timeoutOccurred()?

bool VL53L0X_timeoutOccurred()
{
	bool tmp = VL53L0X.did_timeout;
	VL53L0X.did_timeout = false;
	return tmp;
}

// Private Methods /////////////////////////////////////////////////////////////

// Get reference SPAD (single photon avalanche diode) count and type
// based on VL53L0X_get_info_from_device(),
// but only gets reference SPAD count and type

bool VL53L0X_getSpadInfo(uint8_t * count, bool * type_is_aperture)
{
	uint8_t tmp;

	VL53L0X_writeReg(0x80, 0x01);
	VL53L0X_writeReg(0xFF, 0x01);
	VL53L0X_writeReg(0x00, 0x00);

	VL53L0X_writeReg(0xFF, 0x06);
	VL53L0X_writeReg(0x83, VL53L0X_readReg(0x83) | 0x04);
	VL53L0X_writeReg(0xFF, 0x07);
	VL53L0X_writeReg(0x81, 0x01);

	VL53L0X_writeReg(0x80, 0x01);

	VL53L0X_writeReg(0x94, 0x6b);
	VL53L0X_writeReg(0x83, 0x00);
	startTimeout();
	while (VL53L0X_readReg(0x83) == 0x00) {
		if (checkTimeoutExpired()) {
			return false;
		}
	}
	VL53L0X_writeReg(0x83, 0x01);
	tmp = VL53L0X_readReg(0x92);

	*count = tmp & 0x7f;
	*type_is_aperture = (tmp >> 7) & 0x01;

	VL53L0X_writeReg(0x81, 0x00);
	VL53L0X_writeReg(0xFF, 0x06);
	VL53L0X_writeReg(0x83, VL53L0X_readReg(0x83 & ~0x04));
	VL53L0X_writeReg(0xFF, 0x01);
	VL53L0X_writeReg(0x00, 0x01);

	VL53L0X_writeReg(0xFF, 0x00);
	VL53L0X_writeReg(0x80, 0x00);

	return true;
}

// Get sequence step enables
// based on VL53L0X_GetSequenceStepEnables()

void VL53L0X_getSequenceStepEnables(struct SequenceStepEnables * enables)
{
	uint8_t sequence_config = VL53L0X_readReg(SYSTEM_SEQUENCE_CONFIG);

	enables->tcc = (sequence_config >> 4) & 0x1;
	enables->dss = (sequence_config >> 3) & 0x1;
	enables->msrc = (sequence_config >> 2) & 0x1;
	enables->pre_range = (sequence_config >> 6) & 0x1;
	enables->final_range = (sequence_config >> 7) & 0x1;
}

// Get sequence step timeouts
// based on get_sequence_step_timeout(),
// but gets all timeouts instead of just the requested one, and also stores
// intermediate values

void VL53L0X_getSequenceStepTimeouts(struct SequenceStepEnables const * enables, struct SequenceStepTimeouts * timeouts)
{
	timeouts->pre_range_vcsel_period_pclks = VL53L0X_getVcselPulsePeriod(VcselPeriodPreRange);

	timeouts->msrc_dss_tcc_mclks = VL53L0X_readReg(MSRC_CONFIG_TIMEOUT_MACROP) + 1;
	timeouts->msrc_dss_tcc_us =
			VL53L0X_timeoutMclksToMicroseconds(timeouts->msrc_dss_tcc_mclks,
			timeouts->pre_range_vcsel_period_pclks);

	timeouts->pre_range_mclks =
			VL53L0X_decodeTimeout(VL53L0X_readReg16Bit(PRE_RANGE_CONFIG_TIMEOUT_MACROP_HI));
	timeouts->pre_range_us =
			VL53L0X_timeoutMclksToMicroseconds(timeouts->pre_range_mclks,
			timeouts->pre_range_vcsel_period_pclks);

	timeouts->final_range_vcsel_period_pclks = VL53L0X_getVcselPulsePeriod(VcselPeriodFinalRange);

	timeouts->final_range_mclks =
			VL53L0X_decodeTimeout(VL53L0X_readReg16Bit(FINAL_RANGE_CONFIG_TIMEOUT_MACROP_HI));

	if (enables->pre_range) {
		timeouts->final_range_mclks -= timeouts->pre_range_mclks;
	}

	timeouts->final_range_us =
			VL53L0X_timeoutMclksToMicroseconds(timeouts->final_range_mclks,
			timeouts->final_range_vcsel_period_pclks);
}

// Decode sequence step timeout in MCLKs from register value
// based on VL53L0X_decode_timeout()
// Note: the original function returned a uint32_t, but the return value is
// always stored in a uint16_t.

static uint16_t VL53L0X_decodeTimeout(uint16_t reg_val)
{
	// format: "(LSByte * 2^MSByte) + 1"
	return(uint16_t) ((reg_val & 0x00FF) <<
			(uint16_t) ((reg_val & 0xFF00) >> 8)) + 1;
}

// Encode sequence step timeout register value from timeout in MCLKs
// based on VL53L0X_encode_timeout()
// Note: the original function took a uint16_t, but the argument passed to it
// is always a uint16_t.

static uint16_t VL53L0X_encodeTimeout(uint16_t timeout_mclks)
{
	// format: "(LSByte * 2^MSByte) + 1"

	uint32_t ls_byte = 0;
	uint16_t ms_byte = 0;

	if (timeout_mclks > 0) {
		ls_byte = timeout_mclks - 1;

		while ((ls_byte & 0xFFFFFF00) > 0) {
			ls_byte >>= 1;
			ms_byte++;
		}

		return(ms_byte << 8) | (ls_byte & 0xFF);
	} else {
		return 0;
	}
}

// Convert sequence step timeout from MCLKs to microseconds with given VCSEL period in PCLKs
// based on VL53L0X_calc_timeout_us()

static uint32_t VL53L0X_timeoutMclksToMicroseconds(uint16_t timeout_period_mclks, uint8_t vcsel_period_pclks)
{
	uint32_t macro_period_ns = calcMacroPeriod(vcsel_period_pclks);

	return((timeout_period_mclks * macro_period_ns) + (macro_period_ns / 2)) / 1000;
}

// Convert sequence step timeout from microseconds to MCLKs with given VCSEL period in PCLKs
// based on VL53L0X_calc_timeout_mclks()

static uint32_t VL53L0X_timeoutMicrosecondsToMclks(uint32_t timeout_period_us, uint8_t vcsel_period_pclks)
{
	uint32_t macro_period_ns = calcMacroPeriod(vcsel_period_pclks);

	return(((timeout_period_us * 1000) + (macro_period_ns / 2)) / macro_period_ns);
}


// based on VL53L0X_perform_single_ref_calibration()

bool VL53L0X_performSingleRefCalibration(uint8_t vhv_init_byte)
{
	VL53L0X_writeReg(SYSRANGE_START, 0x01 | vhv_init_byte); // VL53L0X_REG_SYSRANGE_MODE_START_STOP

	startTimeout();
	while ((VL53L0X_readReg(RESULT_INTERRUPT_STATUS) & 0x07) == 0) {
		if (checkTimeoutExpired()) {
			return false;
		}
	}

	VL53L0X_writeReg(SYSTEM_INTERRUPT_CLEAR, 0x01);

	VL53L0X_writeReg(SYSRANGE_START, 0x00);

	return true;
}
