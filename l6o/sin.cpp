#include <iostream>

// Base class
class Animal {
protected:
    std::string name;

public:
    Animal(const std::string& animalName) : name(animalName) {}

    void eat() const {
        std::cout << name << " is eating." << std::endl;
    }

    void sleep() const {
        std::cout << name << " is sleeping." << std::endl;
    }
};

// Derived class inheriting from Animal
class Dog : public Animal {
public:
    Dog(const std::string& dogName) : Animal(dogName) {}

    void bark() const {
        std::cout << name << " is barking." << std::endl;
    }
};

int main() {
    // Creating an instance of the derived class Dog
    Dog myDog("Buddy");

    // Accessing inherited fields and methods from the base class Animal
    myDog.eat();
    myDog.sleep();

    // Accessing the method specific to the derived class Dog
    myDog.bark();

    return 0;
}
