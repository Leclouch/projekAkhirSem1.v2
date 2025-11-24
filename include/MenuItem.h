#ifndef MENUITEM_H
#define MENUITEM_H

#include "Item.h"
#include <string>
#include <sstream>

// ===== MENU ITEM CLASS =====
class MenuItem : public Item {
private:
    int id;           // ID unik untuk setiap menu
    int stock;        // Jumlah stok tersedia

public:
    MenuItem();
    MenuItem(int i, const string& n, int p, int s);

    // Getter methods
    int getId() const;
    int getStock() const;
    
    // Setter methods
    void setId(int i);
    void setStock(int s);
    
    // Tambah/kurang stok
    void decreaseStock(int qty);
    void increaseStock(int qty);
    
    // Konversi ke string untuk file
    string toString() const;

    // Parse dari string
    static MenuItem fromString(const string& line);
};

#endif
