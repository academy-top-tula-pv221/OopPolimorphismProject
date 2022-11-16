#include <iostream>
#include <string>

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
    string Move()
    {
        return Transport::Move() + " with speed: " + to_string(speed);
    }
};

class Plane : public Transport
{
    int height;
public:
    Plane(string type, int height) : Transport(type), height{ height } {}
    string Move()
    {
        return Transport::Move() + " at height: " + to_string(height);
    }
};

int main()
{
    Transport* transport = new Transport("transport");
    Car* car = new Car("car", 200);
    Plane* plane = new Plane("plane", 10000);

    cout << car->Move() << "\n";
    cout << plane->Move() << "\n";

    Transport* transports[3];
    transports[0] = transport;
    transports[1] = car;
    transports[2] = plane;

    for (int i = 0; i < 3; i++)
        cout << transports[i]->Move() << "\n";
}
