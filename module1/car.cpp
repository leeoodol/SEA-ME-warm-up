#include <iostream>
#include <string>
using namespace std;

class Car {
public:
    // Default constructor
    Car() : name(""), speed(0) {
        cout << "Default constructor called" << endl;
    }

    // Parameterized constructor
    Car(const string& carName, int carSpeed) : name(carName), speed(carSpeed) {
        cout << "Parameterized constructor called" << endl;
    }

    // Copy constructor
    Car(const Car& other) : name(other.name), speed(other.speed) {
        cout << "Copy constructor called" << endl;
    }

    // Copy assignment operator
    Car& operator=(const Car& other) {
        cout << "Copy assignment operator called" << endl;
        if (this != &other) {
            name = other.name;
            speed = other.speed;
        }
        return *this;
    }

    // Destructor
    ~Car() {
        cout << "Destructor called" << endl;
    }


    string name;
    int speed;
};


int main() {
    Car car1;  // Default constructor called

    Car car2("Ferrari", 250);  // Parameterized constructor called

    Car car3 = car2;  // Copy constructor called
    
    cout << "car2 is stored at:";
    cout << &car2 << endl;
    cout << "car2 consists of:";
    cout << car2.name;
    cout << car2.speed << endl;

    cout << "car3 is stored at:";
    cout << &car3 << endl;
    cout << "car3 consists of:";
    cout << car3.name; 
    cout << car3.speed << endl;

    Car car4;  // Default constructor called
    car4 = car3;  // Copy assignment operator called

    return 0;
}