#include "Animal.h"

// Реализация базового класса Animal
Animal::Animal() : breed(""), color("") {
    std::cout << "Animal default constructor called." << std::endl;
}

Animal::Animal(const std::string& breed, const std::string& color) : breed(breed), color(color) {
    std::cout << "Animal parameterized constructor called." << std::endl;
}

Animal::Animal(const Animal& other) : breed(other.breed), color(other.color) {
    std::cout << "Animal copy constructor called." << std::endl;
}

Animal::~Animal() {
    std::cout << "Animal destructor called." << std::endl;
}

void Animal::setBreed(const std::string& breed) {
    this->breed = breed;
}

std::string Animal::getBreed() const {
    return breed;
}

void Animal::setColor(const std::string& color) {
    this->color = color;
}

std::string Animal::getColor() const {
    return color;
}

// Реализация класса Fish
Fish::Fish() : Animal(), feedingType("") {
    std::cout << "Fish default constructor called." << std::endl;
}

Fish::Fish(const std::string& breed, const std::string& color, const std::string& feedingType)
    : Animal(breed, color), feedingType(feedingType) {
    std::cout << "Fish parameterized constructor called." << std::endl;
}

Fish::Fish(const Fish& other) : Animal(other), feedingType(other.feedingType) {
    std::cout << "Fish copy constructor called." << std::endl;
}

Fish::~Fish() {
    std::cout << "Fish destructor called." << std::endl;
}

void Fish::display() const {
    std::cout << "Fish [Breed: " << breed << ", Color: " << color << ", Feeding Type: " << feedingType << "]" << std::endl;
}

void Fish::save(std::ostream& out) const {
    out << "Fish\n" << breed << "\n" << color << "\n" << feedingType << std::endl;
}

void Fish::load(std::istream& in) {
    std::getline(in, breed);
    std::getline(in, color);
    std::getline(in, feedingType);
}

void Fish::setFeedingType(const std::string& feedingType) {
    this->feedingType = feedingType;
}

std::string Fish::getFeedingType() const {
    return feedingType;
}

// Реализация класса Bird
Bird::Bird() : Animal(), feedingType(""), habitat("") {
    std::cout << "Bird default constructor called." << std::endl;
}

Bird::Bird(const std::string& breed, const std::string& color, const std::string& feedingType, const std::string& habitat)
    : Animal(breed, color), feedingType(feedingType), habitat(habitat) {
    std::cout << "Bird parameterized constructor called." << std::endl;
}

Bird::Bird(const Bird& other) : Animal(other), feedingType(other.feedingType), habitat(other.habitat) {
    std::cout << "Bird copy constructor called." << std::endl;
}

Bird::~Bird() {
    std::cout << "Bird destructor called." << std::endl;
}

void Bird::display() const {
    std::cout << "Bird [Breed: " << breed << ", Color: " << color << ", Feeding Type: " << feedingType
        << ", Habitat: " << habitat << "]" << std::endl;
}

void Bird::save(std::ostream& out) const {
    out << "Bird\n" << breed << "\n" << color << "\n" << feedingType << "\n" << habitat << std::endl;
}

void Bird::load(std::istream& in) {
    std::getline(in, breed);
    std::getline(in, color);
    std::getline(in, feedingType);
    std::getline(in, habitat);
}

void Bird::setFeedingType(const std::string& feedingType) {
    this->feedingType = feedingType;
}

std::string Bird::getFeedingType() const {
    return feedingType;
}

void Bird::setHabitat(const std::string& habitat) {
    this->habitat = habitat;
}

std::string Bird::getHabitat() const {
    return habitat;
}

// Реализация класса Cat
Cat::Cat() : Animal(), ownerName(""), nickname("") {
    std::cout << "Cat default constructor called." << std::endl;
}

Cat::Cat(const std::string& breed, const std::string& color, const std::string& ownerName, const std::string& nickname)
    : Animal(breed, color), ownerName(ownerName), nickname(nickname) {
    std::cout << "Cat parameterized constructor called." << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other), ownerName(other.ownerName), nickname(other.nickname) {
    std::cout << "Cat copy constructor called." << std::endl;
}

Cat::~Cat() {
    std::cout << "Cat destructor called." << std::endl;
}

void Cat::display() const {
    std::cout << "Cat [Breed: " << breed << ", Color: " << color << ", Owner Name: " << ownerName
        << ", Nickname: " << nickname << "]" << std::endl;
}

void Cat::save(std::ostream& out) const {
    out << "Cat\n" << breed << "\n" << color << "\n" << ownerName << "\n" << nickname << std::endl;
}

void Cat::load(std::istream& in) {
    std::getline(in, breed);
    std::getline(in, color);
    std::getline(in, ownerName);
    std::getline(in, nickname);
}

void Cat::setOwnerName(const std::string& ownerName) {
    this->ownerName = ownerName;
}

std::string Cat::getOwnerName() const {
    return ownerName;
}

void Cat::setNickname(const std::string& nickname) {
    this->nickname = nickname;
}

std::string Cat::getNickname() const {
    return nickname;
}
