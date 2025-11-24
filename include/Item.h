#ifndef ITEM_H
#define ITEM_H

#include <string>
using namespace std;

// ===== BASE CLASS - Item =====
// Kelas dasar untuk MenuItem dan CartItem
class Item {
protected:
    string name;      // Nama item
    int price;        // Harga item
    
public:
    Item();
    Item(const string& n, int p);
    
    virtual ~Item();
    
    // Getter methods
    string getName() const;
    int getPrice() const;
    
    // Setter methods
    void setName(const string& n);
    void setPrice(int p);
};

#endif