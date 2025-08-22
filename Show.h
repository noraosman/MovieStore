//
// ---------------------------------------------------------------------------
// Assignment 4: Movie Store
// Group Members: Kyle Williams(2550507) and Nora Osmanova(2550505)
// Date: 08/12/2025
//
// Description:
// Can be treated as a separate transaction. Shows stock
// ---------------------------------------------------------------------------
//

#ifndef SHOW_H
#define SHOW_H

#include "Transaction.h"
#include "Store.h"
#include "CustomerHashTable.h"

class Show : public Transaction {
public:
    void execute(Store& store, CustomerHashTable& customers);
    bool processData(const std::string& data);
private:
};

#endif
