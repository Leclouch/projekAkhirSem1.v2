#include "CartItem.h"

// Konstruktor default
CartItem::CartItem() : Item(), quantity(0), subtotal(0) {}

// Konstruktor dengan parameter
CartItem::CartItem(const string& n, int p, int q) 
    : Item(n, p), quantity(q), subtotal(p * q) {}

// Getter untuk quantity
int CartItem::getQuantity() const {
    return quantity;
}

// Getter untuk subtotal
int CartItem::getSubtotal() const {
    return subtotal;
}

// Setter untuk quantity dan update subtotal
void CartItem::setQuantity(int q) { 
    quantity = q; 
    subtotal = price * quantity;
}
