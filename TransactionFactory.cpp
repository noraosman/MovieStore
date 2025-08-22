
//
// ---------------------------------------------------------------------------
// Assignment 4: Movie Store
// Group Members: Kyle Williams(2550507) and Nora Osmanova(2550505)
// Date: 08/12/2025
//
// Description:
// Creates Transaction object based on Transaction enum.
// Parses the commands by BRIH codes
//
// ---------------------------------------------------------------------------
//

#include "TransactionFactory.h"

// Creates and returns a Transaction subclass instance based on 'type'
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

			// Check for unknown transaction code
            return nullptr;
    }
}