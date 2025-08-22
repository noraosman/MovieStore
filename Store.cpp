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
#include "Customer.h"

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
    delete movie;
}

void Store::printInventory() {
    inventory.printAllInventories();
}

void Store::addComedy(const Comedy& comedy) {
    inventory.addComedy(comedy);
}
void Store::addDrama(const Drama& drama) {
    inventory.addDrama(drama);
}
void Store::addClassic(const Classic& classic) {
    inventory.addClassic(classic);
}

bool Store::borrowComedy(const std::string& title, int year, Customer* customer) {
    Comedy* movie = inventory.findComedy(title, year);
    if (!movie) {
        std::cerr << "Error: Comedy movie \"" << title << "\" (" << year << ") not found.\n";
        return false;
    }
    if (movie->getStock() <= 0) {
        std::cerr << "Error: Comedy movie \"" << title << "\" (" << year << ") out of stock.\n";
        return false;
    }
    movie->decrementStock();
    customer->addBorrowedMovie(movie);
    return true;
}

bool Store::borrowDrama(const std::string& director, const std::string& title, Customer* customer) {
    Drama* movie = inventory.findDrama(director, title);
    if (!movie) {
        std::cerr << "Error: Drama movie \"" << title << "\" by " << director << " not found.\n";
        return false;
    }
    if (movie->getStock() <= 0) {
        std::cerr << "Error: Drama movie \"" << title << "\" by " << director << " out of stock.\n";
        return false;
    }
    movie->decrementStock();
    customer->addBorrowedMovie(movie);
    return true;
}

bool Store::borrowClassic(int year, int month, const std::string& majorActor, Customer* customer) {
    Classic* movie = inventory.findClassic(year, month, majorActor);
    if (!movie) {
        std::cerr << "Error: Classic movie (" << month << "/" << year << ") starring " << majorActor << " not found.\n";
        return false;
    }
    if (movie->getStock() <= 0) {
        std::cerr << "Error: Classic movie (" << month << "/" << year << ") starring " << majorActor << " out of stock.\n";
        return false;
    }
    movie->decrementStock();
    customer->addBorrowedMovie(movie);
    return true;
}

bool Store::returnComedy(const std::string& title, int year, Customer* customer) {
    Comedy* movie = inventory.findComedy(title, year);
    if (!movie) {
        std::cerr << "Error: Comedy movie \"" << title << "\" (" << year << ") not found for return.\n";
        return false;
    }
    if (!customer->hasBorrowedMovie(movie)) {
        std::cerr << "Error: Customer did not borrow this comedy movie.\n";
        return false;
    }
    movie->incrementStock();
    customer->removeBorrowedMovie(movie);
    return true;
}

bool Store::returnDrama(const std::string& director, const std::string& title, Customer* customer) {
    Drama* movie = inventory.findDrama(director, title);
    if (!movie) {
        std::cerr << "Error: Drama movie \"" << title << "\" by " << director << " not found for return.\n";
        return false;
    }
    if (!customer->hasBorrowedMovie(movie)) {
        std::cerr << "Error: Customer did not borrow this drama movie.\n";
        return false;
    }
    movie->incrementStock();
    customer->removeBorrowedMovie(movie);
    return true;
}

bool Store::returnClassic(int year, int month, const std::string& majorActor, Customer* customer) {
    Classic* movie = inventory.findClassic(year, month, majorActor);
    if (!movie) {
        std::cerr << "Error: Classic movie (" << month << "/" << year << ") starring " << majorActor << " not found for return.\n";
        return false;
    }
    if (!customer->hasBorrowedMovie(movie)) {
        std::cerr << "Error: Customer did not borrow this classic movie.\n";
        return false;
    }
    movie->incrementStock();
    customer->removeBorrowedMovie(movie);
    return true;
}