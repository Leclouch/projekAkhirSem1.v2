#ifndef CARTMANAGER_H
#define CARTMANAGER_H

#include "CartItem.h"
#include "MenuManager.h"
#include <vector>
#include <string>

// ===== CART MANAGER CLASS =====
// Mengelola semua operasi keranjang belanja
class CartManager {
private:
    vector<CartItem> cart;  // Keranjang belanja

    // Helper method untuk menampilkan satu item cart
    void tampilItemCart(int index) const;

public:
    CartManager();

    // Menampilkan keranjang
    void tampilCart() const;

    // Hitung total harga
    int hitungTotal() const;

    // Tambah item ke keranjang
    void tambahKeCart(MenuManager& menuManager);

    // Hapus item dari keranjang
    void hapusDariCart(MenuManager& menuManager);

    // Kembalikan semua stok ketika transaksi dibatalkan
    void returnAllStock(MenuManager& menuManager);

    // Kosongkan keranjang
    void clearCart();

    // Getter
    bool isEmpty() const;

    const vector<CartItem>& getCart() const;
};

#endif
