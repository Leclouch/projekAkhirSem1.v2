#ifndef CARTITEM_H
#define CARTITEM_H

#include "Item.h"
#include <string>

// ===== CART ITEM CLASS =====
class CartItem : public Item {
private:
    int quantity;     // Jumlah yang dibeli
    int subtotal;     // Total harga untuk item ini

public:
    CartItem();
    CartItem(const string& n, int p, int q);

    // Getter methods
    int getQuantity() const;
    int getSubtotal() const;
    
    // Update subtotal ketika quantity berubah
    void setQuantity(int q);
};

#endif
