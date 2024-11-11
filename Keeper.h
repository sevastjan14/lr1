#ifndef KEEPER_H
#define KEEPER_H

#include "Animal.h"

class Keeper {
    Animal** animals;  // Указатель на массив указателей на объекты Animal
    size_t count;      // Количество животных
    size_t capacity;   // Вместимость контейнера

    void resize();  // Метод для увеличения вместимости контейнера

public:
    Keeper();
    ~Keeper();

    void addAnimal(Animal* animal);       // Добавление животного
    void removeAnimal(size_t index);      // Удаление животного
    void displayAll() const;              // Вывод всех животных
    void saveToFile(const std::string& filename) const;  // Сохранение в файл
    void loadFromFile(const std::string& filename);      // Загрузка из файла
};

#endif
