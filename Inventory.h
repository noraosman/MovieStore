#ifndef INVENTORY_H
#define INVENTORY_H

#include <map>
#include <string>
#include "Comedy.h"
#include "Drama.h"
#include "Classic.h"

class Inventory {
public:
    struct ClassicKey {
        int year;
        int releaseMonth;
        std::string majorActorName;
        bool operator<(const ClassicKey& other) const;
    };

    void addComedy(const Comedy& comedy);
    void addDrama(const Drama& drama);
    void addClassic(const Classic& classic);

    Comedy* findComedy(const std::string& title, int year);
    Drama* findDrama(const std::string& director, const std::string& title);
    Classic* findClassic(int year, int releaseMonth, const std::string& majorActorName);

    void printAllInventories();

private:
    std::map<std::pair<std::string, int>, Comedy> comedyInventory;
    std::map<std::pair<std::string, std::string>, Drama> dramaInventory;
    std::map<ClassicKey, Classic> classicInventory;
};

#endif