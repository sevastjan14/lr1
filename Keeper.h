#ifndef KEEPER_H
#define KEEPER_H

#include "Animal.h"

class Keeper {
    Animal** animals;  // ��������� �� ������ ���������� �� ������� Animal
    size_t count;      // ���������� ��������
    size_t capacity;   // ����������� ����������

    void resize();  // ����� ��� ���������� ����������� ����������

public:
    Keeper();
    ~Keeper();

    void addAnimal(Animal* animal);       // ���������� ���������
    void removeAnimal(size_t index);      // �������� ���������
    void displayAll() const;              // ����� ���� ��������
    void saveToFile(const std::string& filename) const;  // ���������� � ����
    void loadFromFile(const std::string& filename);      // �������� �� �����
};

#endif
