#include <iostream>

class Base1 {
public:
    Base1() {
        std::cout << "Base1 constructor" << std::endl;
    }
};

class Base2 {
public:
    Base2() {
        std::cout << "Base2 constructor" << std::endl;
    }
};

class Derived : public Base1, public Base2 {
public:
    Derived() {
        std::cout << "Derived constructor" << std::endl;
    }
};

int main() {
    Derived derivedObj;
    return 0;
}
