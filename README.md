# Standarisasi Dokumentasi Riset (SDR)
---

##  📘 Tentang Riset:

- **Tim/Divisi:** [Nama tim, misal: MEIRO]
- **Tipe Perangkat:** [Misal: STM32]
- **Tanggal Mulai - Selesai:** [dd/mm/yyyy - dd/mm/yyyy]
- **Status:** 🚧 _Dalam Pengembangan_ / ✅ _Selesai_ / 🧪 _Eksperimen_
  
---
## 📚 Latar Belakang

Jelaskan alasan mengapa riset ini dilakukan. Sertakan:
- Masalah teknis atau ilmiah yang hendak diselesaikan.
- Signifikansi atau manfaat dari hasil riset.
- Keterkaitan riset ini dengan perkembangan teknologi atau kebutuhan praktis.

---

## 🎯 Tujuan

Rinci tujuan riset secara umum dan khusus, seperti:
- Tujuan utama yang ingin dicapai.
- Sub-tujuan atau milestone penting dalam proses riset.
- Sasaran fungsional maupun eksperimental.

---

## 📁 Struktur Folder

Jelaskan struktur direktori proyek untuk memudahkan navigasi:

```
📦 SDR                     → File utama
├── 📂 src                 → Source code utama
├── 📂 include             → Header file
│   ├── 📄 arduino.h       → Header arduino
│   └── 📄 wena.h          → Header Wena
├── 📂 DOCS                → Dokumen pendukung dan SDR
└── 📜 README.md           → Tempat SDR
```
---

## 🔬 Metodologi

Tabel berikut merinci tools dan teknologi utama yang digunakan dalam riset ini:

| Komponen           | Deskripsi                                                | Versi                |
|--------------------|----------------------------------------------------------|----------------------|
| Platform           | [ESP32, STM32, Arduino, dsb.]                           |    Versi yang  digunakan  |
| Bahasa Pemrograman  | [C/C++, MicroPython, dsb.]                               |Contoh : 1.11 |
| IDE                | [Arduino IDE, STM32CubeIDE, dsb.]                        ||
| Komunikasi         | [UART, I2C, Bluetooth, WiFi, dsb.]                       ||
| Dependensi         | [Library eksternal atau modul tambahan]                  ||
| Framework          | [Kerangka kerja yang digunakan, misalnya: SPL, STM32 HAL, PlatformIO] ||

- Jelaskan algoritma atau teori yang diterapkan.
- Jelaskan platform atau perangkat keras yang relevan.

---

## ⚙️ Perancangan Sistem

Deskripsikan rancangan sistem secara keseluruhan:
- Diagram arsitektur atau diagram blok sistem (sertakan gambar/link).
- Penjabaran tiap komponen utama dan perannya dalam sistem.
- Relasi antar modul (komunikasi, alur data, kendali, dll).

---

## 🧪 Eksperimen & Evaluasi

Dokumentasikan proses dan hasil pengujian:
- Metode eksperimen: prosedur, skenario uji, setup perangkat.
- Parameter yang diukur dan bagaimana pengukurannya.
- Hasil eksperimen (dapat disertai tabel, grafik, atau referensi file di `/results`).
- Dataset atau input uji yang digunakan.

---

## 📊 Analisis & Pembahasan

Bahas hasil eksperimen secara kritis:
- Interpretasi hasil dan kaitannya dengan tujuan riset.
- Identifikasi kelemahan sistem atau anomali hasil.
- Komparasi dengan metode lain (jika ada).
- Insight teknis yang didapat selama proses riset.

---

## ✅ Kesimpulan & Rencana Lanjut

Tuliskan ringkasan hasil riset:
- Apakah tujuan riset telah tercapai?
- Kontribusi utama dari riset ini.
- Rekomendasi pengembangan lebih lanjut, baik secara teknis maupun arah riset.

---

## 🕒 Riwayat Revisi

Catat setiap perubahan besar pada dokumen ini:

| Versi | Tanggal     | Deskripsi Perubahan       | Penulis       |
|-------|-------------|--------------------------|---------------|
| 1.0   | YYYY-MM-DD  | Deskripsi awal           | Nama          |
| 1.1   | YYYY-MM-DD  | Perubahan besar berikutnya| Nama          |
---

📌 **Catatan:**  
Dokumen SDR ini wajib diperbarui secara berkala, minimal setiap akhir sprint atau fase utama proyek. Gunakan format ini sebagai dasar yang konsisten untuk seluruh tim dalam organisasi riset Workshop Robotika.
