#include "Keeper.h"
#include <iostream>

void showMenu() {
    std::cout << "1. Add Animal\n";
    std::cout << "2. Remove Animal\n";
    std::cout << "3. Display All Animals\n";
    std::cout << "4. Save to File\n";
    std::cout << "5. Load from File\n";
    std::cout << "6. Exit\n";
    std::cout << "Enter your choice: ";
}

int main() {
    Keeper keeper;
    int choice;

    while (true) {
        showMenu();
        std::cin >> choice;

        switch (choice) {
        case 1: {
            int type;
            std::cout << "Choose type (1 - Fish, 2 - Bird, 3 - Cat): ";
            std::cin >> type;

            std::string breed, color, feedingType, habitat, ownerName, nickname;
            std::cin.ignore(); // Очищаем буфер ввода

            std::cout << "Enter breed: ";
            std::getline(std::cin, breed);
            std::cout << "Enter color: ";
            std::getline(std::cin, color);

            Animal* animal = nullptr;
            if (type == 1) {
                std::cout << "Enter feeding type: ";
                std::getline(std::cin, feedingType);
                animal = new Fish(breed, color, feedingType);
            }
            else if (type == 2) {
                std::cout << "Enter feeding type: ";
                std::getline(std::cin, feedingType);
                std::cout << "Enter habitat: ";
                std::getline(std::cin, habitat);
                animal = new Bird(breed, color, feedingType, habitat);
            }
            else if (type == 3) {
                std::cout << "Enter owner's name: ";
                std::getline(std::cin, ownerName);
                std::cout << "Enter nickname: ";
                std::getline(std::cin, nickname);
                animal = new Cat(breed, color, ownerName, nickname);
            }

            if (animal) {
                keeper.addAnimal(animal);
            }
            break;
        }
        case 2: {
            size_t index;
            std::cout << "Enter index of animal to remove: ";
            std::cin >> index;
            try {
                keeper.removeAnimal(index);
            }
            catch (const std::exception& e) {
                std::cerr << e.what() << std::endl;
            }
            break;
        }
        case 3:
            keeper.displayAll();
            break;
        case 4: {
            std::string filename;
            std::cout << "Enter filename to save: ";
            std::cin >> filename;
            try {
                keeper.saveToFile(filename);
            }
            catch (const std::exception& e) {
                std::cerr << e.what() << std::endl;
            }
            break;
        }
        case 5: {
            std::string filename;
            std::cout << "Enter filename to load: ";
            std::cin >> filename;
            try {
                keeper.loadFromFile(filename);
            }
            catch (const std::exception& e) {
                std::cerr << e.what() << std::endl;
            }
            break;
        }
        case 6:
            return 0;
        default:
            std::cerr << "Invalid choice." << std::endl;
        }
    }
}
