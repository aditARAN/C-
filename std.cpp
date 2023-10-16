

#include <iostream>
using namespace std;

#define MAX 10

class emp {
private:
    string name;
    string id,br;
    int ag;

public:
  
    void getDetails(void);

    void putDetails(void);
};

//member function definition, outside of the class
void emp::getDetails(void)
{
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter Employee ID: ";
    cin >> id;
    cout << "Enter Company";
    cin >> br;
    cout<< "Enter age: ";
    cin >> ag;
}

//member function definition, outside of the class
void emp::putDetails(void)
{
    cout << "Emplyee details:\n";
    cout << "Name:" << name << ",Employee ID:" << id << ",Company:" << br <<",Age: "<<ag;
}

int main()
{
    emp std;
    cout << "Enter details of Employee: \n";
    std.getDetails();
    cout << endl;
    cout << "Details of Employee:\n";
    std.putDetails();
    

    return 0;
}
