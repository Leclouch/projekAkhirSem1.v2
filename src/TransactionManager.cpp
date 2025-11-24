#include "TransactionManager.h"
#include <iostream>
#include <fstream>

using namespace std;

// Konstruktor
TransactionManager::TransactionManager() : nextTransId(1) {}

// Membuat struk dan simpan ke file
void TransactionManager::buatStruk(CartManager& cartManager) {
    if (cartManager.getCart().empty()) {
        cout << "Keranjang belanja kosong. Tidak ada yang dibeli.\n";
        return;
    }
    
    cartManager.tampilCart();
    
    // Buat file struk pembelian
    ofstream out("receipt.txt");
    out << "=== STRUK PEMBELIAN ===\n";
    out << "ID Transaksi: " << nextTransId++ << "\n";
    out << "========================\n";
    
    int totalHarga = 0;
    const auto& cart = cartManager.getCart();
    
    for (int i = 0; i < cart.size(); i++) {
        out << (i+1) << ". " << cart[i].getName() << " x" << cart[i].getQuantity() 
            << " @ Rp" << cart[i].getPrice() << " = Rp" << cart[i].getSubtotal() << "\n";
        totalHarga += cart[i].getSubtotal();
    }
    
    out << "========================\n";
    out << "Total: Rp" << totalHarga << "\n";
    out << "========================\n";
    out.close();

    cout << "\nTransaksi berhasil. Struk dicetak ke receipt.txt\n";
    cartManager.clearCart();
}
