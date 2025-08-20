//
// ---------------------------------------------------------------------------
// Assignment 4: MovieFactory
// Group Members: Kyle Williams(2550507) and Nora Osmanova(2550505)
// Date: 08/12/2025
//
// Description:
// ---------------------------------------------------------------------------
//

#include "Movie.h"
#include <iostream>

void Movie::display() {
    std::cout << stock << ", " << director << ", " << title << ", " << year << std::endl;
}