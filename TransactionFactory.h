
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

#ifndef TRANSACTIONFACTORY_H
#define TRANSACTIONFACTORY_H

#include "Borrow.h"
#include "ReturnItem.h"
#include "Show.h"
#include "History.h"

class TransactionFactory {
public:
    // Available types of transactions
    enum class TransactionType{
        Borrow,
        ReturnItem,
        Inventory,
        History
    };

    static Transaction* createTrans(TransactionType type);        // Returns an enum checked transaction.
private:
};

#endif
