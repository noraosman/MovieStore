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

class Drama : public Movie {
public:
    Drama() = default; // Default constructor
    Drama(std::string);
    bool operator<(const Movie& other) const override; // Finished
    bool operator==(const Movie& other) const override; // Finished
    void display(); // Finished
    void processData(std::string) override; // Finished
    //void borrow();
    //void returnMovie();
private:
};
#endif //DRAMA_H
