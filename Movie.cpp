//
// ---------------------------------------------------------------------------
// Assignment 4: MovieStore
// Group Members: Kyle Williams(2550507) and Nora Osmanova(2550505)
// Date: 08/12/2025
//
// ---------------------------------------------------------------------------
// Description:
// Base class functionality for Movie objects
// Implements the display function which prints the basic information of a movie
// (stock, director, title, and year)
// ---------------------------------------------------------------------------
#include "Movie.h"
#include <iostream>


// ---------------------------------------------------------------------------
// Outputs the movie's data in a s comma seperated format
//
void Movie::display() {
    std::cout << stock << ", " << director << ", " << title << ", " << year << std::endl;
}