#include "Keeper.h"
#include <iostream>
#include <fstream>

Keeper::Keeper() : animals(nullptr), count(0), capacity(2) {
    animals = new Animal * [capacity];
}

Keeper::~Keeper() {
    for (size_t i = 0; i < count; ++i) {
        delete animals[i];
    }
    delete[] animals;
}

void Keeper::resize() {
    capacity *= 2;
    Animal** newAnimals = new Animal * [capacity];
    for (size_t i = 0; i < count; ++i) {
        newAnimals[i] = animals[i];
    }
    delete[] animals;
    animals = newAnimals;
}

void Keeper::addAnimal(Animal* animal) {
    if (count == capacity) {
        resize();
    }
    animals[count++] = animal;
}

void Keeper::removeAnimal(size_t index) {
    if (index >= count) {
        throw std::out_of_range("Index out of range");
    }
    delete animals[index];
    for (size_t i = index; i < count - 1; ++i) {
        animals[i] = animals[i + 1];
    }
    --count;
}

void Keeper::displayAll() const {
    for (size_t i = 0; i < count; ++i) {
        animals[i]->display();
    }
}

void Keeper::saveToFile(const std::string& filename) const {
    std::ofstream out(filename);
    if (!out) {
        throw std::runtime_error("Failed to open file for saving");
    }
    out << count << std::endl;
    for (size_t i = 0; i < count; ++i) {
        animals[i]->save(out);
    }
}

void Keeper::loadFromFile(const std::string& filename) {
    std::ifstream in(filename);
    if (!in) {
        throw std::runtime_error("Failed to open file for loading");
    }
    size_t newCount;
    in >> newCount;
    in.ignore();

    for (size_t i = 0; i < count; ++i) {
        delete animals[i];
    }
    delete[] animals;

    animals = new Animal * [newCount];
    count = 0;
    capacity = newCount;

    std::string type;
    for (size_t i = 0; i < newCount; ++i) {
        std::getline(in, type);
        Animal* animal = nullptr;
        if (type == "Fish") {
            animal = new Fish();
        }
        else if (type == "Bird") {
            animal = new Bird();
        }
        else if (type == "Cat") {
            animal = new Cat();
        }
        if (animal) {
            animal->load(in);
            animals[count++] = animal;
        }
    }
}
