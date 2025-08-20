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
#include "MovieFactory.h"

void Store::loadMovie(std::string data) {
    Movie* movie = nullptr;
    if (data[0] == 'C') {
        movie = MovieFactory::createMovie(MovieFactory::MovieGenre::Classic);
        movie->processData(data);
        inventory.addClassic(*static_cast<Classic*>(movie));
    } else if (data[0] == 'D') {
        movie = MovieFactory::createMovie(MovieFactory::MovieGenre::Drama);
        movie->processData(data);
        inventory.addDrama(*static_cast<Drama*>(movie));
    } else if (data[0] == 'F') {
        movie = MovieFactory::createMovie(MovieFactory::MovieGenre::Comedy);
        movie->processData(data);
        inventory.addComedy(*static_cast<Comedy*>(movie));
    } else {
        std::cerr << "Unknown movie type in data: " << data << std::endl;
        return;
    }
    delete movie; // Clean up heap allocation
}

void Store::printInventory() {
    inventory.printAllInventories();
}