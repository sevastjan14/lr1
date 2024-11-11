#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
#include <iostream>

class Animal {
protected:
    std::string breed;
    std::string color;

public:
    Animal();
    Animal(const std::string& breed, const std::string& color);
    Animal(const Animal& other);
    virtual ~Animal();

    virtual void display() const = 0;
    virtual void save(std::ostream& out) const = 0;
    virtual void load(std::istream& in) = 0;

    void setBreed(const std::string& breed);
    std::string getBreed() const;

    void setColor(const std::string& color);
    std::string getColor() const;
};

// Производный класс Fish
class Fish : public Animal {
    std::string feedingType;

public:
    Fish();
    Fish(const std::string& breed, const std::string& color, const std::string& feedingType);
    Fish(const Fish& other);
    ~Fish();

    void display() const override;
    void save(std::ostream& out) const override;
    void load(std::istream& in) override;

    void setFeedingType(const std::string& feedingType);
    std::string getFeedingType() const;
};

// Производный класс Bird
class Bird : public Animal {
    std::string feedingType;
    std::string habitat;

public:
    Bird();
    Bird(const std::string& breed, const std::string& color, const std::string& feedingType, const std::string& habitat);
    Bird(const Bird& other);
    ~Bird();

    void display() const override;
    void save(std::ostream& out) const override;
    void load(std::istream& in) override;

    void setFeedingType(const std::string& feedingType);
    std::string getFeedingType() const;

    void setHabitat(const std::string& habitat);
    std::string getHabitat() const;
};

// Производный класс Cat
class Cat : public Animal {
    std::string ownerName;
    std::string nickname;

public:
    Cat();
    Cat(const std::string& breed, const std::string& color, const std::string& ownerName, const std::string& nickname);
    Cat(const Cat& other);
    ~Cat();

    void display() const override;
    void save(std::ostream& out) const override;
    void load(std::istream& in) override;

    void setOwnerName(const std::string& ownerName);
    std::string getOwnerName() const;

    void setNickname(const std::string& nickname);
    std::string getNickname() const;
};

#endif
