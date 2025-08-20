#ifndef INVENTORY_H
#define INVENTORY_H

#include <map>
#include "Comedy.h"
#include "Drama.h"
#include "Classic.h"
#include <iostream>

class Inventory {
public:
    void addComedy(const Comedy& comedy) {
        comedyInventory[{comedy.getTitle(), comedy.getYear()}] = comedy;
    }

    void addDrama(const Drama& drama) {
        dramaInventory[{drama.getDirector(), drama.getTitle()}] = drama;
    }

    void addClassic(const Classic& classic) {
        classicInventory[{classic.getYear(), classic.getReleaseMonth(), classic.getMajorActorName()}] = classic;
    }
    /////////////////////////
    void printAllInventories() {
        std::cout << "Comedy Inventory:" << std::endl;
        for (auto& pair : comedyInventory) {
            pair.second.display();
        }
        std::cout << std::endl;

        std::cout << "Drama Inventory:" << std::endl;
        for (auto& pair : dramaInventory) {
            pair.second.display();
        }
        std::cout << std::endl;

        std::cout << "Classic Inventory:" << std::endl;
        for (auto& pair : classicInventory) {
            pair.second.display();
        }
        std::cout << std::endl;
    }
    ////////////////////////


private:
    // Comedy: key = (title, year)
    std::map<std::pair<std::string, int>, Comedy> comedyInventory;

    // Drama: key = (director, title)
    std::map<std::pair<std::string, std::string>, Drama> dramaInventory;

    // Classic: key = (year, month, majorActor)
    struct ClassicKey {
        int year;
        int releaseMonth;
        std::string majorActorName;
        bool operator<(const ClassicKey& other) const {
            return std::tie(year, releaseMonth, majorActorName) <
                   std::tie(other.year, other.releaseMonth, other.majorActorName);
        }
    };
    std::map<ClassicKey, Classic> classicInventory;
};
#endif