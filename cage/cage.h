#ifndef CAGE_H
#define CAGE_H

#include <iostream>
#include <string>

using namespace std;

class Cage {
private:
    string cageType;
    string location;
    int capacity;
    int currentOccupancy;

public:
    Cage(string cageType, string location, int capacity);

    void setCageType(string cageType);
    void setLocation(string location);
    void setCapacity(int capacity);
    void setCurrentOccupancy(int currentOccupancy);

    string getCageType() const;
    string getLocation() const;
    int getCapacity() const;
    int getCurrentOccupancy() const;

    void addAnimal();
    void removeAnimal();
    void displayCageInfo() const;
};

#endif
