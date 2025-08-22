//
// ---------------------------------------------------------------------------
// Assignment 4: Movie Store
// Group Members: Kyle Williams(2550507) and Nora Osmanova(2550505)
// Date: 08/12/2025
//
// Description:
// The Store class manages a hash table of customers and an inventory of movies.
//	It can load and find movies, load and find custoemrs, print the inventory,
//  and handle transactions(borrowing and returning)
// ---------------------------------------------------------------------------
//

#include "Classic.h"
#include "Drama.h"
#include "Comedy.h"
#include "Store.h"
#include <iostream>
#include "MovieFactory.h"
#include "Customer.h"


// ---------------------------------------------------------------------------
// Loads a movie from a string of data into the inventory
// C for Classic, D for drama, F for Comedy
// ---------------------------------------------------------------------------
void Store::loadMovie(std::string data) {
    Movie* movie = nullptr;

//Classic Movie
    if (data[0] == 'C') {
        movie = MovieFactory::createMovie(MovieFactory::MovieGenre::Classic); 			// Creates a Classic movie in movieFactory
        movie->processData(data);														// Parse movie info from data
        inventory.addClassic(*static_cast<Classic*>(movie));							// Adds the movie to Classic Inventory

//Drama Movie
    } else if (data[0] == 'D') {
        movie = MovieFactory::createMovie(MovieFactory::MovieGenre::Drama);
        movie->processData(data);
        inventory.addDrama(*static_cast<Drama*>(movie));

//Comedy Movie
    } else if (data[0] == 'F') {
        movie = MovieFactory::createMovie(MovieFactory::MovieGenre::Comedy);
        movie->processData(data);
        inventory.addComedy(*static_cast<Comedy*>(movie));

// Invalid movie type
    } else {
        std::cerr << "Unknown movie type in data: " << data << std::endl;
        return;
    }
    delete movie;				//deletes the temporary pointer after adding to inventory
}



// ---------------------------------------------------------------------------
// Prints the entire movie inventory of all genres
// ---------------------------------------------------------------------------
void Store::printInventory() {
    inventory.printAllInventories();
}

// ---------------------------------------------------------------------------
// Adds specific movie to the inventory
// ---------------------------------------------------------------------------
void Store::addComedy(const Comedy& comedy) {
    inventory.addComedy(comedy);
}
void Store::addDrama(const Drama& drama) {
    inventory.addDrama(drama);
}
void Store::addClassic(const Classic& classic) {
    inventory.addClassic(classic);
}


// ---------------------------------------------------------------------------
// Borrows a comedy movie for a customer if available
// Checks that the movie exists and has stock left.
// Updates inventory and customer's borrowed list.
// ---------------------------------------------------------------------------
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
    movie->decrementStock();				// reduce stock
    customer->addBorrowedMovie(movie);		// add movie to customer's borrowed list
    return true;
}


// ---------------------------------------------------------------------------
// Borrows drama movie, identified by director and title
// ---------------------------------------------------------------------------
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


// ---------------------------------------------------------------------------
// Borrows classic movie, identified release month and year and major actor.
// ---------------------------------------------------------------------------
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


// ---------------------------------------------------------------------------
// Returns a Comedy movie. Verifies to see if the customer borrowed it first
// ---------------------------------------------------------------------------
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
    movie->incrementStock();			// increase the stock
    customer->removeBorrowedMovie(movie);
    return true;
}

// ---------------------------------------------------------------------------
// Returns a Drama movie. Verifies to see if the customer borrowed it first
// ---------------------------------------------------------------------------
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

// ---------------------------------------------------------------------------
// Returns a Comedy movie. Verifies to see if the customer borrowed it first
// ---------------------------------------------------------------------------
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