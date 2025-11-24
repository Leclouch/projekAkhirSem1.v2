# ProjekAkhirSem1.v2 — Sistem Kantin (C++)

Sistem Kantin sederhana berbasis konsol yang dibuat dalam bahasa C++. Proyek ini memungkinkan pengelolaan menu kantin, keranjang pesanan, transaksi, dan pembuatan struk.

## Fitur

- Menambahkan, mengedit, dan menghapus item menu  
- Menampilkan menu saat startup dari file `data/input.txt`  
- Menambah item ke keranjang  
- Melihat dan menghapus item di keranjang  
- Checkout transaksi dan mencetak struk  
- Membatalkan transaksi dan mengembalikan stok  

## Struktur Direktori

```
projekAkhirSem1.v2/
│
├── data/
│   └── input.txt              # File menu awal
├── include/
│   ├── Kantin.h  
│   ├── MenuManager.h  
│   ├── CartManager.h  
│   └── TransactionManager.h  
├── src/
│   ├── Kantin.cpp  
│   ├── MenuManager.cpp  
│   ├── CartManager.cpp  
│   ├── TransactionManager.cpp  
│   └── main.cpp  
└── kantin.exe                 # (atau file .out jika di Linux)
```

## Cara Build

Gunakan **g++** untuk mengompilasi kode:

1. Buka terminal / command prompt di direktori proyek:  
   ```bash
   cd D:\@Kuliah\Programan Dasar\projekAkhirSem1.v2
   ```
2. Jalankan perintah berikut:  
   ```bash
   g++ -Iinclude src/*.cpp -o kantin.exe
   ```

   Penjelasan:
   - `-Iinclude`: menambahkan direktori header  
   - `src/*.cpp`: mengompilasi semua file .cpp  
   - `-o kantin.exe`: menghasilkan executable `kantin.exe`

## Cara Menjalankan

Setelah kompilasi selesai, jalankan dengan:

```bash
./kantin.exe
```

atau di Windows:

```powershell
kantin.exe
```

Pastikan `data/input.txt` berada di folder `data/` dalam direktori yang sama dengan executable atau jalankan dari direktori root proyek agar file bisa dibaca.

## Format File `input.txt`

File `input.txt` berisi daftar menu awal. Contoh format (misalnya):

```
Nasi Goreng, 15000, 20  
Mie Ayam, 12000, 30  
Es Teh, 5000, 50  
```

Kolom: **nama item**, **harga (int)**, **stok (int)** — dipisah koma.

## Contoh Alur Penggunaan

1. Program dijalankan → `initialize()` membaca `input.txt`.  
2. Menu utama tampil: tambah/edit/hapus menu, transaksi, dsb.  
3. Jika pilih “Transaksi”:
   - Lihat menu  
   - Tambah item ke keranjang  
   - Lihat keranjang  
   - Hapus item dari keranjang jika perlu  
   - Checkout → struk dicetak  
   - Jika batal → stok dikembalikan  
4. Setelah transaksi, kembali ke menu utama atau keluar.

## Catatan

- Saat `input.txt` tidak ditemukan, program memulai dengan menu kosong dan Anda bisa menambahkan item secara manual.  
- Pastikan path file `input.txt` benar di `Kantin::initialize()`.  

## Pengembangan / Kontribusi

- Anda bisa menambahkan fitur penyimpanan menu otomatis setelah edit.  
- Buat sistem login (admin / user) jika ingin memperluas.  
- Sistem bisa diperluas ke GUI (Qt atau lainnya).  

## Penulis

*[Nama Kamu]* — (ganti dengan namamu)
