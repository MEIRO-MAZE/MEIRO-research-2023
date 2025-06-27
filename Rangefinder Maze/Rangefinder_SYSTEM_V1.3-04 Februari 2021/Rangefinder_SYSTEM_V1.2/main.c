#include "main.h"
unsigned int COMMAND_FLAG_A = 0x3C;
unsigned int COMMAND_FLAG_B = 0x3E;
int nilai_ADC;
int kanan,kiri;
int data_sharp2 = 0;

void ClockSetup()//  system and peripheral clock setup
{
      RCC_DeInit ();                    /* RCC system reset(for debug purpose)*/
      RCC_HSEConfig (RCC_HSE_ON);       /* Enable HSE                         */

      /* Wait till HSE is ready                                               */
      while (RCC_GetFlagStatus(RCC_FLAG_HSERDY) == RESET);

      RCC_HCLKConfig   (RCC_SYSCLK_Div1);   /* HCLK   = SYSCLK                */
      RCC_PCLK2Config  (RCC_HCLK_Div1);     /* PCLK2  = HCLK                  */
      RCC_PCLK1Config  (RCC_HCLK_Div2);     /* PCLK1  = HCLK/2                */
      RCC_ADCCLKConfig (RCC_PCLK2_Div6);    /* ADCCLK = PCLK2/4               */

      /* PLLCLK = 8MHz * 9 = 72 MHz                                           */
      RCC_PLLConfig (0x00010000, RCC_PLLMul_9);

      RCC_PLLCmd (ENABLE);                  /* Enable PLL                     */

      /* Wait till PLL is ready                                               */
      while (RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET);

      /* Select PLL as system clock source                                    */
      RCC_SYSCLKConfig (RCC_SYSCLKSource_PLLCLK);

      /* Wait till PLL is used as system clock source                         */
      while (RCC_GetSYSCLKSource() != 0x08);
}

void SetSysClockTo72(void)
{
	ErrorStatus HSEStartUpStatus;
    /* SYSCLK, HCLK, PCLK2 and PCLK1 configuration -----------------------------*/
    /* RCC system reset(for debug purpose) */
    RCC_DeInit();

    /* Enable HSE */
    RCC_HSEConfig( RCC_HSE_ON);

    /* Wait till HSE is ready */
    HSEStartUpStatus = RCC_WaitForHSEStartUp();

    if (HSEStartUpStatus == SUCCESS)
    {
        /* Enable Prefetch Buffer */
    	//FLASH_PrefetchBufferCmd( FLASH_PrefetchBuffer_Enable);

        /* Flash 2 wait state */
        //FLASH_SetLatency( FLASH_Latency_2);

        /* HCLK = SYSCLK */
        RCC_HCLKConfig( RCC_SYSCLK_Div1);

        /* PCLK2 = HCLK */
        RCC_PCLK2Config( RCC_HCLK_Div1);

        /* PCLK1 = HCLK/2 */
        RCC_PCLK1Config( RCC_HCLK_Div2);

        /* PLLCLK = 8MHz * 9 = 72 MHz */
        RCC_PLLConfig(0x00010000, RCC_PLLMul_9);

        /* Enable PLL */
        RCC_PLLCmd( ENABLE);

        /* Wait till PLL is ready */
        while (RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET)
        {
        }

        /* Select PLL as system clock source */
        RCC_SYSCLKConfig( RCC_SYSCLKSource_PLLCLK);

        /* Wait till PLL is used as system clock source */
        while (RCC_GetSYSCLKSource() != 0x08)
        {
        }
    }
    else
    {
        while (1)
        {
        }
    }
}

int main(void)
{
	SetSysClockTo72();
	BW_ADC_Init();
//	ADCInit();
	USART1_Init(115200);
	DelayInit();
	RCC->APB2ENR |= RCC_APB2ENR_AFIOEN; AFIO->MAPR = AFIO_MAPR_SWJ_CFG_1; // Remap JTAG Debugger di PB3 PB4, agar dapat dipakai GPIO biasa
	PING_TIM_Init();
//	IR_CAT_Init();
//	UV_GPIO_Init();
	DelayMs(120); // delay stabilisasi SHARP IR
    while(1)
    {
    	USART_Send(USART1, COMMAND_FLAG_A);
    	USART_Send(USART1, COMMAND_FLAG_B);

    	PingScan(PING_FRONT);USART_Send(USART1,distance[PING_FRONT]);			//case 1
    	PingScan(PING_REAR);USART_Send(USART1,distance[PING_REAR]);				//case 2
    	DelayMs(5);

    	PingScan(ASKEW_FR);USART_Send(USART1,distance[ASKEW_FR]);				//case 3
    	PingScan(ASKEW_FL);USART_Send(USART1, distance[ASKEW_FL]);				//case 4
    	DelayMs(5);

    	PingScan(ASKEW_RR);USART_Send(USART1,distance[ASKEW_RR]);				//case 5
    	PingScan(ASKEW_RL);USART_Send(USART1,distance[ASKEW_RL]);				//case 6
    	DelayMs(5);

    	PingScan(PING_R);USART_Send(USART1,distance[PING_R]);					//case 7
    	PingScan(PING_L);USART_Send(USART1,distance[PING_L]);					//case 8
    	DelayMs(5);

    	SHARP_IR_read(IR_FRONT);USART_Send(USART1,sharp_data[IR_FRONT]);		//case 9
    	SHARP_IR_read(IR_LEFT);USART_Send(USART1,sharp_data[IR_LEFT]);			//case 10
    	SHARP_IR_read(IR_RIGHT);USART_Send(USART1,sharp_data[IR_RIGHT]);		//case 11
       	DelayMs(5);

    }
}
