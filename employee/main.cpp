#include "employee.h"
#include <vector>

int main() {
    vector<employee*> employees;

    employees.push_back(new manager("Alice", 1, "Manager", 5000, "Day", {"Bob", "Charlie"}));
    employees.push_back(new veterinarian("Bob", 2, "Veterinarian", 4000, "Night", {"Canine", "Feline"}));
    employees.push_back(new zookeeper("Charlie", 3, "Zookeeper", 3000, "Day", {"Lions", "Tigers"}));

    for (employee* emp : employees) {
        emp->work();
    }

    for (employee* emp : employees) {
        delete emp;
    }

    return 0;
}
