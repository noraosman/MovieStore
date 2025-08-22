//
// ---------------------------------------------------------------------------
// Assignment 4: MovieStore
// Group Members: Kyle Williams(2550507) and Nora Osmanova(2550505)
// Date: 08/12/2025
//
// Description:
// Inherits attributes from Inventory aka Movie class
// Has comparison, display and stock management functions
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

    // Comparison operators
    bool operator<(const Movie& other) const override;
    bool operator==(const Movie& other) const override;

    // Prints movie info
    void display();

    // Process input data string to set Drama movie attributes
    void processData(std::string) override;

    //Stock management
    int getStock() const;
    void decrementStock();
    void incrementStock();
private:
};
#endif //DRAMA_H
