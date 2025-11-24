#include "MenuManager.h"
#include <iostream>
#include <fstream>

using namespace std;

// Konstruktor
MenuManager::MenuManager() : nextMenuId(1) {}

// Destruktor (optional, but good practice)
MenuManager::~MenuManager() {}

// Memuat data menu dari file
void MenuManager::loadMenu(const string& filename) {
    ifstream in(filename);
    
    if (!in) {
        cout << "File " << filename << " tidak ditemukan, mulai dengan menu kosong.\n";
        return;
    }
    
    string line;
    while (getline(in, line)) {
        if (line.empty()) continue;
        MenuItem m = MenuItem::fromString(line);
        menu.push_back(m);
        if (m.getId() >= nextMenuId) nextMenuId = m.getId() + 1;
    }
    in.close();
    cout << "Menu berhasil dimuat dari " << filename << ".\n";
}

// Menambahkan menu item baru
void MenuManager::tambahMenu() {
    MenuItem m;
    m.setId(nextMenuId++);
    
    cout << "Nama menu: "; 
    cin.ignore();
    string name;
    getline(cin, name);
    m.setName(name);
    
    cout << "Harga: "; 
    int price;
    cin >> price;
    m.setPrice(price);
    
    cout << "Stok: "; 
    int stock;
    cin >> stock;
    m.setStock(stock);
    
    menu.push_back(m);
    cout << "Menu ditambahkan.\n";
}

// Menampilkan semua menu
void MenuManager::tampilMenu() const {
    cout << "\n=== Daftar Menu ===\n";
    for (const auto &m : menu) {
        cout << m.getId() << ". " << m.getName() << " - Rp" << m.getPrice()
             << " (stok " << m.getStock() << ")\n";
    }
}

// Mengedit menu
void MenuManager::editMenu() {
    tampilMenu();
    
    int id;
    cout << "\nID menu yang ingin diedit: ";
    cin >> id;
    
    for (auto &m : menu) {
        if (m.getId() == id) {
            cout << "Nama baru (" << m.getName() << "): "; 
            cin.ignore();
            string name;
            getline(cin, name);
            m.setName(name);
            
            cout << "Harga baru (" << m.getPrice() << "): "; 
            int price;
            cin >> price;
            m.setPrice(price);
            
            cout << "Stok baru (" << m.getStock() << "): "; 
            int stock;
            cin >> stock;
            m.setStock(stock);
            
            cout << "Menu diperbarui.\n";
            return;
        }
    }
    cout << "Menu tidak ditemukan.\n";
}

// Menghapus menu
void MenuManager::hapusMenu() {
    tampilMenu();
    
    int id;
    cout << "\nID menu yang ingin dihapus: ";
    cin >> id;
    
    for (auto it = menu.begin(); it != menu.end(); ++it) {
        if (it->getId() == id) {
            menu.erase(it);
            cout << "Menu dihapus.\n";
            return;
        }
    }
    cout << "Menu tidak ditemukan.\n";
}

// Cari menu berdasarkan ID
MenuItem* MenuManager::findMenuById(int id) {
    for (auto &m : menu) {
        if (m.getId() == id) {
            return &m;
        }
    }
    return nullptr;
}

// Getter untuk menu vector
const vector<MenuItem>& MenuManager::getMenu() const {
    return menu;
}
