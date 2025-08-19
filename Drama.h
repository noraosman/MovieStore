//
// ---------------------------------------------------------------------------
// Assignment 4: Movie Store
// Group Members: Kyle Williams(2550507) and Nora Osmanova(2550505)
// Date: 08/12/2025
//
// Description:
// Inherits attributes from Inventory aka Movie class.
// ---------------------------------------------------------------------------
//


#ifndef DRAMA_H
#define DRAMA_H
#include "Movie.h"
#include "MovieFactory.h"

class Drama{
public:
    void operator<(Movie);
    void operator==(Movie);
    void display();             //displays the information of comedy class movie
    void processData();
private:
    std::string majorActorName;
    int releaseDate;
};
#endif //DRAMA_H
