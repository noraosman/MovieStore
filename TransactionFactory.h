
//
// ---------------------------------------------------------------------------
// Assignment 4: Movie Store
// Group Members: Kyle Williams(2550507) and Nora Osmanova(2550505)
// Date: 08/12/2025
//
// Description:
// Reads the text file and seperates into categories based on BRIH
// ---------------------------------------------------------------------------
//

#include "Transaction.h"

#ifndef TRANSACTIONFACTORY_H
#define TRANSACTIONFACTORY_H

class TransactionFactory {
public:
    // Available types of transactions
    enum class TransactionType{
        Borrow,
        Return,
        Inventory,
        History
    };

    Transaction static createTrans(TransactionType);        // Returns an enum checked transaction.
private:
};

#endif TRANSACTIONFACTORY_H
