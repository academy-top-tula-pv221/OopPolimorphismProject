#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Transport
{
protected:
    string type;
public:
    Transport(string type = "") : type{type} {}
    
    virtual string Move()
    {
        return type + " move";
    }
};

class Car : public Transport
{
    int speed;
public:
    Car(string type, int speed) : Transport(type), speed{ speed } {}
    
    string Move() override
    {
        return Transport::Move() + " with speed: " + to_string(speed);
    }

    void CarMethod()
    {
        cout << "Hello car\n";
    }
};

class Plane : public Transport
{
    int height;
public:
    Plane(string type, int height) : Transport(type), height{ height } {}
    
    string Move() override
    {
        return Transport::Move() + " at height: " + to_string(height);
    }
};

class PoliceCar : public Car
{
public:
    PoliceCar(string type, int speed) : Car(type, speed) {}

    string Move() override
    {
        return Car::Move() + " ua-ua-ua";
    }
};

int main()
{
    Transport* transports[3];
    transports[0] = new Transport("transport");
    transports[1] = new Car("car", 200);
    transports[2] = new Plane("plane", 10000);
    

    for (int i = 0; i < 3; i++)
        cout << transports[i]->Move() << "\n";

    PoliceCar pcar("police car", 190);
    cout << pcar.Move();
}
