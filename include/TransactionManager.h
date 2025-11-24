#ifndef TRANSACTIONMANAGER_H
#define TRANSACTIONMANAGER_H

#include "CartManager.h"
#include <string>

// ===== TRANSACTION MANAGER CLASS =====
// Mengelola semua operasi transaksi
class TransactionManager {
private:
    int nextTransId;  // ID transaksi berikutnya

public:
    TransactionManager();

    // Membuat struk dan simpan ke file
    void buatStruk(CartManager& cartManager);
};

#endif
