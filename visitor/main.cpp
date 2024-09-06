#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "animal.h"
#include "cage.h"
#include "employee.h"
#include "visitor.h"

using namespace std;

void menu() {
    cout << "\n";
    cout << "> Here are the things that you could do < \n";
    cout << "option 1 : Show all Animals \n";
    cout << "option 2 : Show all Cage \n";
    cout << "option 3 : Show all Employee \n";
    cout << "option 4 : Show all Visitor \n";
    cout << "option 5 : Add Animal \n";
    cout << "option 6 : Remove Animal \n";
    cout << "option 7 : Search Animal \n";
    cout << "option 8 : Add Cage \n";
    cout << "option 9 : Remove Cage \n";
    cout << "option 10 : Search Cage \n";
    cout << "option 11 : Add Employee \n";
    cout << "option 12 : Remove Employee \n";
    cout << "option 13 : Search Employee \n";
    cout << "option 14 : Add Visitor \n";
    cout << "option 15 : Remove Visitor \n";
    cout << "option 16 : Search Visitor \n";
    cout << "option 17 : Sorting \n";
    cout << "option 0 : Exit \n";
}

bool compareByAge(Animal *a, Animal *b) {
    return a->getAge() < b->getAge();
}

void showAllAnimals(const vector<Animal *> &animals) {
    for (Animal *animal : animals) {
        cout << animal->getName() << " (" << animal->getAge() << " years old)" << endl;
        animal->eat();
        cout << "\n";
        animal->sleep();
        cout << "\n";
        animal->makeSound();
        cout << "\n";
    }
}

void addAnimal(vector<Animal *> &animals) {
    string name, species, gender;
    int age, type;

    cout << "Enter animal type (1-Mammal, 2-Bird, 3-Reptile, 4-Fish, 5-Bug): ";
    cin >> type;
    cout << "Enter name: ";
    cin >> ws; // clear whitespace
    getline(cin, name);
    cout << "Enter species: ";
    getline(cin, species);
    cout << "Enter age: ";
    cin >> age;
    cout << "Enter gender: ";
    cin >> ws;
    getline(cin, gender);

    switch (type) {
    case 1:
        animals.push_back(new Mammal(name, species, age, gender));
        break;
    case 2:
        animals.push_back(new Bird(name, species, age, gender));
        break;
    case 3:
        animals.push_back(new Reptile(name, species, age, gender));
        break;
    case 4:
        animals.push_back(new Fish(name, species, age, gender));
        break;
    case 5:
        animals.push_back(new Bug(name, species, age, gender));
        break;
    default:
        cout << "Invalid type!" << endl;
    }
}

void removeAnimal(vector<Animal *> &animals) {
    string name;
    cout << "Enter the name of the animal to remove: ";
    cin >> ws;
    getline(cin, name);

    auto it = remove_if(animals.begin(), animals.end(), [&](Animal *animal) {
        return animal->getName() == name;
    });

    if (it != animals.end()) {
        delete *it;
        animals.erase(it, animals.end());
        cout << "Animal removed." << endl;
    } else {
        cout << "Animal not found." << endl;
    }
}

void searchAnimal(const vector<Animal *> &animals) {
    string name;
    cout << "Enter the name of the animal to search: ";
    cin >> ws;
    getline(cin, name);

    auto it = find_if(animals.begin(), animals.end(), [&](Animal *animal) {
        return animal->getName() == name;
    });

    if (it != animals.end()) {
        cout << "Animal found: " << (*it)->getName() << " (" << (*it)->getAge() << " years old)" << endl;
    } else {
        cout << "Animal not found." << endl;
    }
}


void showAllEmployees(const vector<employee *> &employees) {
    for (employee *emp : employees) {
        cout << emp->getDetails() << endl;
    }
}

void addEmployee(vector<employee *> &employees) {
    string name, position, shift;
    int employeeID;
    double salary;

    cout << "Enter name: ";
    cin >> ws;
    getline(cin, name);
    cout << "Enter employee ID: ";
    cin >> employeeID;
    cout << "Enter position: ";
    cin >> ws;
    getline(cin, position);
    cout << "Enter salary: ";
    cin >> salary;
    cout << "Enter shift: ";
    cin >> ws;
    getline(cin, shift);

    employees.push_back(new employee(name, employeeID, position, salary, shift));
}

void removeEmployee(vector<employee *> &employees) {
    int employeeID;
    cout << "Enter the employee ID to remove: ";
    cin >> employeeID;

    auto it = remove_if(employees.begin(), employees.end(), [&](employee *emp) {
        return emp->getEmployeeID() == employeeID;
    });

    if (it != employees.end()) {
        delete *it;
        employees.erase(it, employees.end());
        cout << "Employee removed." << endl;
    } else {
        cout << "Employee not found." << endl;
    }
}

void searchEmployee(const vector<employee *> &employees) {
    int employeeID;
    cout << "Enter the employee ID to search: ";
    cin >> employeeID;

    auto it = find_if(employees.begin(), employees.end(), [&](employee *emp) {
        return emp->getEmployeeID() == employeeID;
    });

    if (it != employees.end()) {
        cout << "Employee found: " << (*it)->getDetails() << endl;
    } else {
        cout << "Employee not found." << endl;
    }
}

void showAllVisitors(const vector<Visitor> &visitors) {
    for (const Visitor &visitor : visitors) {
        cout << "Name: " << visitor.getName() << "\nAge: " << visitor.getAge() << "\nTicket Type: " << visitor.getTicketType() << "\nEntry Time: " << visitor.getEntryTime() << endl;
    }
}

void addVisitor(vector<Visitor> &visitors) {
    string name, ticketType, entryTime;
    int age;

    cout << "Enter name: ";
    cin >> ws;
    getline(cin, name);
    cout << "Enter age: ";
    cin >> age;
    cout << "Enter ticket type: ";
    cin >> ws;
    getline(cin, ticketType);
    cout << "Enter entry time: ";
    getline(cin, entryTime);

    visitors.push_back(Visitor(name, age, ticketType, entryTime));
}

void removeVisitor(vector<Visitor> &visitors) {
    string name;
    cout << "Enter the name of the visitor to remove: ";
    cin >> ws;
    getline(cin, name);

    auto it = remove_if(visitors.begin(), visitors.end(), [&](const Visitor &visitor) {
        return visitor.getName() == name;
    });

    if (it != visitors.end()) {
        visitors.erase(it, visitors.end());
        cout << "Visitor removed." << endl;
    } else {
        cout << "Visitor not found." << endl;
    }
}

void searchVisitor(const vector<Visitor> &visitors) {
    string name;
    cout << "Enter the name of the visitor to search: ";
    cin >> ws;
    getline(cin, name);

    auto it = find_if(visitors.begin(), visitors.end(), [&](const Visitor &visitor) {
        return visitor.getName() == name;
    });

    if (it != visitors.end()) {
        cout << "Visitor found: " << "Name: " << it->getName() << "\nAge: " << it->getAge() << "\nTicket Type: " << it->getTicketType() << "\nEntry Time: " << it->getEntryTime() << endl;
    } else {
        cout << "Visitor not found." << endl;
    }
}

int main() {
    vector<Animal *> animals;
    vector<Cage> cages;
    vector<employee *> employees;
    vector<Visitor> visitors;

    while (true) {
        menu();
        int option;
        cout << "Enter your option: ";
        cin >> option;

        switch (option) {
        case 1:
            showAllAnimals(animals);
            break;
        case 2:
            showAllCages(cages);
            break;
        case 3:
            showAllEmployees(employees);
            break;
        case 4:
            showAllVisitors(visitors);
            break;
        case 5:
            addAnimal(animals);
            break;
        case 6:
            removeAnimal(animals);
            break;
        case 7:
            searchAnimal(animals);
            break;
        case 8:
            addCage(cages);
            break;
        case 9:
            removeCage(cages);
            break;
        case 10:
            searchCage(cages);
            break;
        case 11:
            addEmployee(employees);
            break;
        case 12:
            removeEmployee(employees);
            break;
        case 13:
            searchEmployee(employees);
            break;
        case 14:
            addVisitor(visitors);
            break;
        case 15:
            removeVisitor(visitors);
            break;
        case 16:
            searchVisitor(visitors);
            break;
        case 17:
            sort(animals.begin(), animals.end(), compareByAge);
            cout << "Animals sorted by age." << endl;
            break;
        case 0:
            // Clean up dynamically allocated memory
            for (Animal *animal : animals) {
                delete animal;
            }
            for (employee *emp : employees) {
                delete emp;
            }
            return 0;
        default:
            cout << "Invalid option!" << endl;
        }
    }

    return 0;
}
