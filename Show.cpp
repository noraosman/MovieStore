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

#include "Show.h"
#include <string>
#include "Store.h"
#include "CustomerHashTable.h"

bool Show::processData(const std::string& data) {
    return true;
}

void Show::execute(Store& store, CustomerHashTable& customers) {
    store.printInventory();
}