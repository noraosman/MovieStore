//
// ---------------------------------------------------------------------------
// Assignment 4: Movie Store
// Group Members: Kyle Williams(2550507) and Nora Osmanova(2550505)
// Date: 08/12/2025
//
// Description:
// Inventory of the movies based on stock, director title and year.
// ---------------------------------------------------------------------------
//

#ifndef MOVIE_H
#define MOVIE_H

#include <string>

class Movie{
public:
    virtual void operator<(Movie) = 0;
    virtual void operator==(Movie) = 0;
    virtual void display() = 0;
    virtual void processData() = 0;
    virtual void borrow() = 0;
    virtual void returnMovie() = 0;
private:
    int stock;
    std::string director;
    std::string title;
    int year;
};
#endif
