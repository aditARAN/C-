#include <iostream>

class Counter {
private:
    int count;

public:
    Counter() : count(0) {}

    // Prefix increment (++counter)
    Counter operator++() {
        ++count;
        return *this;
    }

    // Postfix increment (counter++)
    Counter operator++(int) {
        Counter temp = *this;
        ++count;
        return temp;
    }

    int getCount() const {
        return count;
    }
};

int main() {
    Counter myCounter;

    // Prefix increment
    ++myCounter;
    std::cout << "After prefix increment: " << myCounter.getCount() << std::endl;

    // Postfix increment
    Counter anotherCounter = myCounter++;
    std::cout << "After postfix increment: " << myCounter.getCount() << std::endl;
    std::cout << "Value before postfix increment: " << anotherCounter.getCount() << std::endl;
    system("pause>0");
}
