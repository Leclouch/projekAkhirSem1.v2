#ifndef MENUMANAGER_H
#define MENUMANAGER_H

#include "MenuItem.h"
#include <vector>
#include <string>

// ===== MENU MANAGER CLASS =====
// Mengelola semua operasi menu
class MenuManager {
private:
    vector<MenuItem> menu;  // Menyimpan semua menu items
    int nextMenuId;         // ID berikutnya untuk menu baru

public:
    MenuManager();
    ~MenuManager();

    // Memuat data menu dari file
    void loadMenu(const string& filename);

    // Menambahkan menu item baru
    void tambahMenu();

    // Menampilkan semua menu
    void tampilMenu() const;

    // Mengedit menu
    void editMenu();

    // Menghapus menu
    void hapusMenu();

    // Cari menu berdasarkan ID
    MenuItem* findMenuById(int id);

    // Getter untuk menu vector
    const vector<MenuItem>& getMenu() const;
};

#endif
