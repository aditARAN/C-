#include <iostream>

// Base class
class Base {
private:
    int privateMember;

public:
    int publicMember;

    Base() : privateMember(0), publicMember(0) {}

    void setPrivateMember(int value) {
        privateMember = value;
    }

    int getPrivateMember() const {
        return privateMember;
    }

    void display() const {
        std::cout << "Base class - privateMember: " << privateMember << ", publicMember: " << publicMember << std::endl;
    }
};

// Derived class
class Derived : public Base {
public:
    void modifyBaseMembers() {
        // Accessing publicMember (inherited as public)
        publicMember = 42;

        // Accessing setPrivateMember and getPrivateMember (inherited as private)
        setPrivateMember(99);
        int privateValue = getPrivateMember();

        // Accessing display() (inherited as public)
        display();

        std::cout << "Derived class - Accessing privateMember via public methods: " << privateValue << std::endl;
    }
};

int main() {
    Derived derivedObject;

    // Accessing publicMember (inherited as public)
    derivedObject.publicMember = 100;

    // Uncommenting the line below would result in a compilation error
    // derivedObject.privateMember = 50;  // Error: 'int Base::privateMember' is private within this context

    // Uncommenting the line below would result in a compilation error
    // int privateValue = derivedObject.getPrivateMember();  // Error: 'int Base::getPrivateMember() const' is private within this context

    // Accessing display() (inherited as public)
    derivedObject.display();

    // Accessing modifyBaseMembers() which internally accesses privateMember via public methods
    derivedObject.modifyBaseMembers();

    return 0;
}
