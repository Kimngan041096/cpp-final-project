#ifndef PET_H
#define PET_H

#include <string>
using namespace std;

struct Pet {
    string name;
    string type;
    int age;
    bool adopted;
};

void addPet(Pet pets[], int &count);
void viewPets(Pet pets[], int count);
void viewPets(Pet pets[], int count, string type); // Overloaded
void adoptPet(Pet pets[], int &count);
void savePets(Pet pets[], int count, const string& filename);
void loadPets(Pet pets[], int &count, const string& filename);
void displayWelcome();
bool isValidName(const string& name);

#endif
