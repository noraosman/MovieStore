//
// ---------------------------------------------------------------------------
// Assignment 4:MovieStore
// Group Members: Kyle Williams(2550507) and Nora Osmanova(2550505)
// Date: 08/12/2025
//
// ---------------------------------------------------------------------------
// Description:
// The inventory class stores and retrieves movies by genre
// Comedy movies are identified by title and year
// Drama movies are identified by director and title
// Classic movies are identified by Classic Key which identified by release date and actor
// Can do insertion, lookup, and a method to print all inventories
// ---------------------------------------------------------------------------


#ifndef INVENTORY_H
#define INVENTORY_H

#include <map>
#include <string>
#include "Comedy.h"
#include "Drama.h"
#include "Classic.h"

class Inventory {
public:
    // Key used for Classic movies
    struct ClassicKey {
        int year;
        int releaseMonth;
        std::string majorActorName;
        bool operator<(const ClassicKey& other) const;
    };

    // Adds movies to the inventory
    void addComedy(const Comedy& comedy);
    void addDrama(const Drama& drama);
    void addClassic(const Classic& classic);

    // Find movies by their key fields
    Comedy* findComedy(const std::string& title, int year);
    Drama* findDrama(const std::string& director, const std::string& title);
    Classic* findClassic(int year, int releaseMonth, const std::string& majorActorName);

    // Prints all movies in the inventory
    void printAllInventories();

private:
    // Maps tore movies using different keys of each genre
    std::map<std::pair<std::string, int>, Comedy> comedyInventory;
    std::map<std::pair<std::string, std::string>, Drama> dramaInventory;
    std::map<ClassicKey, Classic> classicInventory;
};

#endif