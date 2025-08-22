//
// ---------------------------------------------------------------------------
// Assignment 4: Movie Store
// Group Members: Kyle Williams(2550507) and Nora Osmanova(2550505)
// Date: 08/12/2025
//
// Description:
// Reads fron the data4movies.txt file and creates a movie object based on
// category. F for Funny, D for Drama and C for Classics
// ---------------------------------------------------------------------------
//

#include "MovieFactory.h"

// Creates and returns movie subclasses based on genre
Movie* MovieFactory::createMovie(MovieGenre type) {
    switch (type) {
        case MovieGenre::Comedy:
            return new Comedy();
        case MovieGenre::Drama:
            return new Drama();
        case MovieGenre::Classic:
            return new Classic();
        default:
            return nullptr; // or throw an exception
    }
}