#include "Pet.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cctype>

void displayWelcome() {
    cout << R"(
     ____       _   _     _ 
    |  _ \ ___ | |_| |__ (_)
    | |_) / _ \| __| '_ \| |
    |  __/ (_) | |_| | | | |
    |_|   \___/ \__|_| |_|_|

    Welcome to PetPal - Adopt a Pet Today!
    )" << endl;
}

bool isValidName(const string& name) {
    for (char ch : name) {
        if (!isalpha(ch) && ch != ' ') return false;
    }
    return !name.empty();
}

void addPet(Pet pets[], int &count) {
    if (count >= 100) {
        cout << "Pet limit reached!" << endl;
        return;
    }

    Pet p;
    cout << "Enter pet name: ";
    getline(cin, p.name);
    if (!isValidName(p.name)) {
        cout << "Invalid name." << endl;
        return;
    }

    cout << "Enter pet type (e.g., Dog, Cat): ";
    getline(cin, p.type);

    cout << "Enter age: ";
    cin >> p.age;
    if (cin.fail() || p.age < 0) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid age." << endl;
        return;
    }
    cin.ignore(); // flush newline
    p.adopted = false;
    pets[count++] = p;
    cout << "Pet added successfully!" << endl;
}

void viewPets(Pet pets[], int count) {
    cout << left << setw(10) << "Name" << setw(10) << "Type" << setw(5) << "Age" << endl;
    for (int i = 0; i < count; i++) {
        if (!pets[i].adopted) {
            cout << left << setw(10) << pets[i].name << setw(10) << pets[i].type << setw(5) << pets[i].age << endl;
        }
    }
}

void viewPets(Pet pets[], int count, string type) {
    for (int i = 0; i < count; i++) {
        if (!pets[i].adopted && pets[i].type == type) {
            cout << pets[i].name << " (" << pets[i].age << " yrs)" << endl;
        }
    }
}

void adoptPet(Pet pets[], int &count) {
    string name;
    cout << "Enter the name of the pet to adopt: ";
    getline(cin, name);
    for (int i = 0; i < count; i++) {
        if (pets[i].name == name && !pets[i].adopted) {
            pets[i].adopted = true;
            cout << name << " has been adopted!" << endl;
            return;
        }
    }
    cout << "Pet not found or already adopted." << endl;
}

void savePets(Pet pets[], int count, const string& filename) {
    ofstream file(filename);
    for (int i = 0; i < count; i++) {
        file << pets[i].name << "," << pets[i].type << "," << pets[i].age << "," << pets[i].adopted << endl;
    }
    file.close();
}

void loadPets(Pet pets[], int &count, const string& filename) {
    ifstream file(filename);
    count = 0;
    while (!file.eof()) {
        getline(file, pets[count].name, ',');
        getline(file, pets[count].type, ',');
        file >> pets[count].age;
        file.ignore();
        file >> pets[count].adopted;
        file.ignore();
        count++;
    }
    file.close();
}
