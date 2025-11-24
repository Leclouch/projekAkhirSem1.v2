#ifndef KANTIN_H
#define KANTIN_H

#include "MenuManager.h"
#include "CartManager.h"
#include "TransactionManager.h"
#include <string>

// ===== KANTIN CLASS (Main Orchestrator) =====
// Mengatur semua manager dan flow aplikasi
class Kantin {
private:
    MenuManager menuManager;
    CartManager cartManager;
    TransactionManager transactionManager;

public:
    Kantin();

    // Load menu saat startup
    void initialize();

    // Menu transaksi
    void transaksi();

    // Menu utama
    void run();
};

#endif
