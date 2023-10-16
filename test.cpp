#include <iostream>
using namespace std;

class MyClass {
  
    protected:   // Protected access specifier
        int z;  // Protected attribute
    private:   // Private access specifier
        int y;   // Private attribute
    public:
    int x;
        //the getter function
        int getValue() {
            return this->y;
        }
        //the setter function
        void setValue(int _value) {
            this->y = _value;
        }

};

int main() {
  MyClass myObj;
  int a;
  myObj.x = 25;  // Allowed (x is public)
  myObj.setValue(15);  // Not allowed (y is private)
  a=myObj.getValue();
  cout<<"Y= "<<a;
  myObj.z=69;
  return 0;
}
