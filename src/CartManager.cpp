#include "CartManager.h"
#include <iostream>

using namespace std;

// Konstruktor
CartManager::CartManager() {}

// Menampilkan keranjang
void CartManager::tampilCart() const {
    if (cart.empty()) {
        cout << "Keranjang belanja kosong.\n";
        return;
    }
    
    cout << "\n=== Keranjang Belanja ===\n";
    int totalHarga = hitungTotal();
    
    for (int i = 0; i < cart.size(); i++) {
        tampilItemCart(i);
    }
    
    cout << "------------------------\n";
    cout << "Total: Rp" << totalHarga << "\n";
}

// Helper method untuk menampilkan satu item cart
void CartManager::tampilItemCart(int index) const {
    cout << (index+1) << ". " << cart[index].getName() << " x" << cart[index].getQuantity() 
         << " @ Rp" << cart[index].getPrice() << " = Rp" << cart[index].getSubtotal() << "\n";
}

// Hitung total harga
int CartManager::hitungTotal() const {
    int total = 0;
    for (const auto &item : cart) {
        total += item.getSubtotal();
    }
    return total;
}

// Tambah item ke keranjang
void CartManager::tambahKeCart(MenuManager& menuManager) {
    menuManager.tampilMenu();
    
    int id;
    cout << "\nID menu yang dipilih: ";
    cin >> id;
    
    MenuItem* menuItem = menuManager.findMenuById(id);
    
    if (menuItem == nullptr) {
        cout << "Menu tidak ditemukan.\n";
        return;
    }
    
    int qty;
    cout << "Jumlah beli: ";
    cin >> qty;
    
    if (menuItem->getStock() < qty) {
        cout << "Stok tidak cukup. Stok tersedia: " << menuItem->getStock() << "\n";
        return;
    }
    
    // Kurangi stok
    menuItem->decreaseStock(qty);
    
    // Tambah ke keranjang
    CartItem item(menuItem->getName(), menuItem->getPrice(), qty);
    cart.push_back(item);
    cout << item.getName() << " ditambahkan ke keranjang.\n";
}

// Hapus item dari keranjang
void CartManager::hapusDariCart(MenuManager& menuManager) {
    if (cart.empty()) {
        cout << "Keranjang belanja kosong.\n";
        return;
    }
    
    tampilCart();
    
    int idx;
    cout << "Nomor item yang ingin dihapus (0 untuk batal): ";
    cin >> idx;
    
    if (idx > 0 && idx <= cart.size()) {
        // Kembalikan stok ke menu
        for (auto &m : (vector<MenuItem>&)menuManager.getMenu()) {
            if (m.getName() == cart[idx-1].getName()) {
                m.increaseStock(cart[idx-1].getQuantity());
                break;
            }
        }
        
        cart.erase(cart.begin() + idx - 1);
        cout << "Item dihapus dari keranjang.\n";
    } else if (idx != 0) {
        cout << "Nomor tidak valid.\n";
    }
}

// Kembalikan semua stok ketika transaksi dibatalkan
void CartManager::returnAllStock(MenuManager& menuManager) {
    for (const auto &item : cart) {
        for (auto &m : (vector<MenuItem>&)menuManager.getMenu()) {
            if (m.getName() == item.getName()) {
                m.increaseStock(item.getQuantity());
                break;
            }
        }
    }
    cart.clear();
}

// Kosongkan keranjang
void CartManager::clearCart() {
    cart.clear();
}

// Getter
bool CartManager::isEmpty() const {
    return cart.empty();
}

const vector<CartItem>& CartManager::getCart() const {
    return cart;
}
