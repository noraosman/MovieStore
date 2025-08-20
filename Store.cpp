//
// ---------------------------------------------------------------------------
// Assignment 4: Movie Store
// Group Members: Kyle Williams(2550507) and Nora Osmanova(2550505)
// Date: 08/12/2025
//
// Description:
// has hash table of customers for easy lookup and inventory of the movies
// can load and find movies, load and find customers, print inventory and start
// a transaction.
// ---------------------------------------------------------------------------
//

#include "Classic.h"
#include "Drama.h"
#include "Comedy.h"
#include "Store.h"
#include <iostream>

void Store::loadMovie(std::string data) {
    if (data[0] == 'C') {
        Classic* movie = new Classic(data);
        inventory.addClassic(*movie);
    } else if (data[0] == 'D') {
        Drama* movie = new Drama(data);
        inventory.addDrama(*movie);
    } else if (data[0] == 'F') {
        Comedy* movie = new Comedy(data);
        inventory.addComedy(*movie);
    } else {
        std::cerr << "Unknown movie type in data: " << data << std::endl;
    }
}

void Store::printInventory() {
    inventory.printAllInventories();
}