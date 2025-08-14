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
#ifndef INVENTORY_H
#define INVENTORY_H

#include "Movie.h"

class Inventory {
public:
    void showInventory(Movie);
    void showInventoryHelper(Movie);
    bool addMovie(Movie);
private:
    Movie comedyRoot;
    Movie classicRoot;
    Movie dramaRoot;
};

#endif INVENTORY_H
