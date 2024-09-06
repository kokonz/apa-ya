#include "cage.h"

Cage::Cage(string cageType, string location, int capacity)
    : cageType(cageType), location(location), capacity(capacity), currentOccupancy(0) {}

void Cage::setCageType(string cageType) {
    this->cageType = cageType;
}

void Cage::setLocation(string location) {
    this->location = location;
}

void Cage::setCapacity(int capacity) {
    this->capacity = capacity;
}

void Cage::setCurrentOccupancy(int currentOccupancy) {
    this->currentOccupancy = currentOccupancy;
}

string Cage::getCageType() const {
    return this->cageType;
}

string Cage::getLocation() const {
    return this->location;
}

int Cage::getCapacity() const {
    return this->capacity;
}

int Cage::getCurrentOccupancy() const {
    return this->currentOccupancy;
}

void Cage::addAnimal() {
    if (currentOccupancy < capacity) {
        currentOccupancy++;
        cout << "Animal added to the cage." << endl;
    } else {
        cout << "Cage is full." << endl;
    }
}

void Cage::removeAnimal() {
    if (currentOccupancy > 0) {
        currentOccupancy--;
        cout << "Animal removed from the cage." << endl;
    } else {
        cout << "Cage is empty." << endl;
    }
}

void Cage::displayCageInfo() const {
    cout << "Cage Type: " << cageType << "\nLocation: " << location
         << "\nCapacity: " << capacity << "\nCurrent Occupancy: " << currentOccupancy << endl;
}
