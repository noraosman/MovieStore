//
// ---------------------------------------------------------------------------
// Assignment 4: Movie Store
// Group Members: Kyle Williams(2550507) and Nora Osmanova(2550505)
// Date: 08/12/2025
//
// Description:
// 
// ---------------------------------------------------------------------------
//

#ifndef HISTORY_H
#define HISTORY_H

#include "Transaction.h"

class History : public Transaction {
public:
    bool processData(const std::string& data) override;
    void execute(Store& store, CustomerHashTable& customers) override;
private:
    int customerID;
};

#endif