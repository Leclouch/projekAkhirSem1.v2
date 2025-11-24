#include "MenuItem.h"

// Konstruktor default
MenuItem::MenuItem() : Item(), id(0), stock(0) {}

// Konstruktor dengan parameter
MenuItem::MenuItem(int i, const string& n, int p, int s) 
    : Item(n, p), id(i), stock(s) {}

// Getter untuk ID
int MenuItem::getId() const {
    return id;
}

// Getter untuk stok
int MenuItem::getStock() const {
    return stock;
}

// Setter untuk ID
void MenuItem::setId(int i) {
    id = i;
}

// Setter untuk stok
void MenuItem::setStock(int s) {
    stock = s;
}

// Kurangi stok
void MenuItem::decreaseStock(int qty) {
    stock -= qty;
}

// Tambah stok
void MenuItem::increaseStock(int qty) {
    stock += qty;
}

// Konversi MenuItem ke string format "id|name|price|stock"
string MenuItem::toString() const {
    ostringstream os;
    os << id << "|" << name << "|" << price << "|" << stock;
    return os.str();
}

// Parse string format "id|name|price|stock" menjadi MenuItem
MenuItem MenuItem::fromString(const string& line) {
    MenuItem m;
    size_t p1 = line.find('|'), p2 = line.find('|', p1+1), p3 = line.find('|', p2+1);
    m.id = stoi(line.substr(0, p1));
    m.name = line.substr(p1+1, p2-p1-1);
    m.price = stoi(line.substr(p2+1, p3-p2-1));
    m.stock = stoi(line.substr(p3+1));
    return m;
}
