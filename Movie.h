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
    virtual ~Movie() = default; // Virtual destructor for proper cleanup of derived classes
    virtual bool operator<(const Movie&) const = 0; // Finished
    virtual bool operator==(const Movie&) const = 0; // Finished
    void display(); // Finished
    virtual void processData(std::string) = 0;
    const std::string& getTitle() const { return title; }
    int getYear() const { return year; }
    const std::string& getDirector() const { return director; }
protected:
    int stock;
    std::string director;
    std::string title;
    int year;
};
#endif
