
//
// ---------------------------------------------------------------------------
// Assignment 4: Movie Store
// Group Members: Kyle Williams(2550507) and Nora Osmanova(2550505)
// Date: 08/12/2025
//
// Description:
// Reads the text file and separates into categories based on BRIH
// ---------------------------------------------------------------------------
//

#include "TransactionFactory.h"

Transaction* TransactionFactory::createTrans(TransactionType type) {
    switch (type) {
        case TransactionType::Borrow:
            return new Borrow();
        case TransactionType::ReturnItem:
            return new ReturnItem();
        case TransactionType::Show:
            return new Show();
        case TransactionType::History:
            return new History();
        default:
            return nullptr;
    }
}