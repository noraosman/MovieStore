//
// ---------------------------------------------------------------------------
// Assignment 4: MovieFactory
// Group Members: Kyle Williams(2550507) and Nora Osmanova(2550505)
// Date: 08/12/2025
//
// Description:
// Inherits attributes from Inventory aka Movie class.
// ---------------------------------------------------------------------------
//

#ifndef COMEDY_H
#define COMEDY_H
#include "Movie.h"
#include "MovieFactory.h"

class Comedy{
public:
    void operator<(Movie);
    void operator==(Movie);
    void display();             //displays the information of comedy class movie
    void processData();
private:
    std::string majorActorName;
    int releaseDate;
};
#endif //COMEDY_H
