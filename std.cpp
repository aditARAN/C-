// C++ program to create student class, read and print N student's details
// (Example of array of objects)

#include <iostream>
using namespace std;

#define MAX 10

class stud {
public:
    string name;
    string id,br;
    //member function to get student's details
    void getDetails(void);
    //member function to print student's details
    void putDetails(void);
};

//member function definition, outside of the class
void stud::getDetails(void)
{
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter roll number: ";
    cin >> id;
    cout << "Enter Branch";
    cin >> br;
}

//member function definition, outside of the class
void stud::putDetails(void)
{
    cout << "Student details:\n";
    cout << "Name:" << name << ",Roll Number:" << id << ",Branch:" << br ;
}

int main()
{
    stud std;
    cout << "Enter details of student: \n";
    std.getDetails();
    cout << endl;
    cout << "Details of student:\n";
    std.putDetails();
    

    return 0;
}
