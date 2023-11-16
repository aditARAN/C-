#include <iostream>

// First base class for addition
class Addition {
public:
    int add(int a, int b) const {
        return a + b;
    }
};

// Second base class for multiplication
class Multiplication {
public:
    int multiply(int a, int b) const {
        return a * b;
    }
};

// Derived class inheriting from both Addition and Multiplication
class Calculator : public Addition, public Multiplication {
public:
    int performOperations(int x, int y) const {
        // Using the add() method from Addition base class
        int sum = add(x, y);
        std::cout << "Sum: " << sum << std::endl;

        // Using the multiply() method from Multiplication base class
        int product = multiply(x, y);
        std::cout << "Product: " << product << std::endl;

        // Returning the result of the addition and multiplication
        return sum + product;
    }
};

int main() {
    // Creating an instance of the derived class Calculator
    Calculator calculator;

    // Performing arithmetic operations using multiple inheritance
    int result = calculator.performOperations(3, 4);

    // Displaying the final result
    std::cout << "Final Result: " << result << std::endl;

    return 0;
}
