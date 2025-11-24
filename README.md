# ProjekAkhirSem1.v2 — Sistem Kantin (C++)

Projek Akhir Semester 1. Sistem Kantin sederhana berbasis konsol yang dibuat dalam bahasa C++. Proyek ini memungkinkan pengelolaan menu kantin, keranjang pesanan, transaksi, dan pembuatan struk.

## Langsung klik "kantin.exe" untuk menjalankan programnya

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
│   └── input.txt
├── include/
│   ├── CartItem.h
│   ├── CartManager.h
│   ├── Item.h
│   ├── Kantin.h
│   ├── MenuItem.h
│   ├── MenuManager.h
│   └── TransactionManager.h
├── src/
│   ├── CartItem.cpp
│   ├── CartManager.cpp
│   ├── Item.cpp
│   ├── Kantin.cpp
│   ├── main.cpp
│   ├── MenuItem.cpp
│   ├── MenuManager.cpp
│   └── TransactionManager.cpp
└── kantin.exe              # 
```

## Cara Menjalankan
Jalankan dengan:

```bash
./kantin.exe
```

atau di Windows:

```powershell
kantin.exe
```

Pastikan `data/input.txt` berada di folder `data/` dalam direktori yang sama dengan executable atau jalankan dari direktori root proyek agar file bisa dibaca.

## Format File `input.txt`

File `input.txt` berisi daftar menu awal. Dengan format:
"(id)|(Nama ItemMenu)|(Harga)|(Jumlah Stok)"

Contoh penulisan format pada "input.txt"

```
1|Nasi Goreng|15000|20
2|Mie Ayam|12000|25
3|Soto Ayam|18000|15
```


## Contoh Alur Penggunaan

1. Program dijalankan → `initialize()` membaca `input.txt`.  
2. Menu utama tampil: 

...
Menu berhasil dimuat dari data/input.txt.

=== Sistem Kantin ===
1. Tambah menu
2. Edit menu
3. Hapus menu
4. Tampilkan menu
5. Transaksi
0. Keluar
Pilih:
...
3. Jika pilih “Transaksi”:
   - Lihat menu  
   - Tambah item ke keranjang  
   - Lihat keranjang  
   - Hapus item dari keranjang jika perlu  
   - Checkout → struk dicetak  
   - Jika batal → stok dikembalikan  
4. Setelah transaksi, kembali ke menu utama dan mengeluarkan output "receipt.txt" yang berisikan struk pembelanjaan kita.

## Catatan

- Saat `input.txt` tidak ditemukan, program memulai dengan menu kosong dan Anda bisa menambahkan item secara manual.  
- Pastikan file `input.txt` benar pathnya di `data/input.txt`.  

## Penulis

Muhammad Wafdan Taqiyya (25/555458/TK/62628)
Gary Christian Wijaya (25/555305/TK/62611)
Muhammad Fazli (25/560578/TK/63319)
