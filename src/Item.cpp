#include "Item.h"

// Konstruktor default
Item::Item() : price(0) {}

// Konstruktor dengan parameter
Item::Item(const string& n, int p) : name(n), price(p) {}

// Destruktor virtual
Item::~Item() {}

// Getter untuk nama
string Item::getName() const {
    return name;
}

// Getter untuk harga
int Item::getPrice() const {
    return price;
}

// Setter untuk nama
void Item::setName(const string& n) {
    name = n;
}

// Setter untuk harga
void Item::setPrice(int p) {
    price = p;
}
