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
#include "Inventory.h"
#include <iostream>
#include <tuple>

// ClassicKey comparison operator
bool Inventory::ClassicKey::operator<(const ClassicKey& other) const {
    return std::tie(year, releaseMonth, majorActorName) <
           std::tie(other.year, other.releaseMonth, other.majorActorName);
}

// Add methods
void Inventory::addComedy(const Comedy& comedy) {
    comedyInventory[{comedy.getTitle(), comedy.getYear()}] = comedy;
}

void Inventory::addDrama(const Drama& drama) {
    dramaInventory[{drama.getDirector(), drama.getTitle()}] = drama;
}

void Inventory::addClassic(const Classic& classic) {
    classicInventory[{classic.getYear(), classic.getReleaseMonth(), classic.getMajorActorName()}] = classic;
}

// Find methods
Comedy* Inventory::findComedy(const std::string& title, int year) {
    auto it = comedyInventory.find({title, year});
    if (it != comedyInventory.end()) return &(it->second);
    return nullptr;
}

Drama* Inventory::findDrama(const std::string& director, const std::string& title) {
    auto it = dramaInventory.find({director, title});
    if (it != dramaInventory.end()) return &(it->second);
    return nullptr;
}

Classic* Inventory::findClassic(int year, int releaseMonth, const std::string& majorActorName) {
    ClassicKey key{year, releaseMonth, majorActorName};
    auto it = classicInventory.find(key);
    if (it != classicInventory.end()) return &(it->second);
    return nullptr;
}

// Print all inventories
void Inventory::printAllInventories() {
    std::cout << "Comedy Inventory:" << std::endl;
    for (auto& pair : comedyInventory) {
        pair.second.display();
    }
    std::cout << std::endl;

    std::cout << "Drama Inventory:" << std::endl;
    for (auto& pair : dramaInventory) {
        pair.second.display();
    }
    std::cout << std::endl;

    std::cout << "Classic Inventory:" << std::endl;
    for (auto& pair : classicInventory) {
        pair.second.display();
    }
    std::cout << std::endl;
}

