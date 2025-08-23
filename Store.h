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


#ifndef STORE_H
#define STORE_H

#include "Movie.h"
#include <string>
#include "Inventory.h"
#include "Customer.h"

class Store{
public:
    void loadMovie(std::string);

     Store() = default;
    ~Store() = default;

    // Borrow/Return for each genre
    bool borrowComedy(const std::string& title, int year, Customer* customer);
    bool borrowDrama(const std::string& director, const std::string& title, Customer* customer);
    bool borrowClassic(int year, int month, const std::string& majorActor, Customer* customer);

    bool returnComedy(const std::string& title, int year, Customer* customer);
    bool returnDrama(const std::string& director, const std::string& title, Customer* customer);
    bool returnClassic(int year, int month, const std::string& majorActor, Customer* customer);

    void printInventory();

    // Add movies to inventory
    void addComedy(const Comedy& comedy);
    void addDrama(const Drama& drama);
    void addClassic(const Classic& classic);

    Inventory& getInventory() { return inventory; }

private:
    Inventory inventory;
};


#endif
