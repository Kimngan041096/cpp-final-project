#include <iostream>
#include "Pet.h"
using namespace std;

int main() {
    Pet pets[100];
    int petCount = 0;
    string filename = "pets.txt";

    loadPets(pets, petCount, filename);
    displayWelcome();

    int choice;
    do {
        cout << "\n1. Add Pet\n2. View Pets\n3. View by Type\n4. Adopt Pet\n5. Save & Exit\nEnter choice: ";
        cin >> choice;
        cin.ignore(); // flush newline

        switch (choice) {
            case 1: addPet(pets, petCount); break;
            case 2: viewPets(pets, petCount); break;
            case 3: {
                string type;
                cout << "Enter type to filter: ";
                getline(cin, type);
                viewPets(pets, petCount, type);
                break;
            }
            case 4: adoptPet(pets, petCount); break;
            case 5: {
                savePets(pets, petCount, filename);
                cout << "Data saved. Goodbye!" << endl;
                break;
            }
            default: cout << "Invalid option!" << endl;
        }
    } while (choice != 5);

    return 0;
}
