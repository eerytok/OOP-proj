#include <iostream>
#include <string>
#include <vector>

class Transport {
protected:
    std::string name;
    double maxSpeed;
    static int count;

public:
    Transport(const std::string& name, double maxSpeed)
        : name(name), maxSpeed(maxSpeed) {
        count++;
    }

    ~Transport() {
        count--;
    }

    static int getCount() { return count; }

    std::string getName() const { return name; }
    double getMaxSpeed() const { return maxSpeed; }

    void printInfo() const {
        std::cout << "Transport: " << name
             << ", max speed: " << maxSpeed << " km/h" << std::endl;
    }

    virtual void move() const {
        std::cout << name << " is moving somewhere." << std::endl;
    }
};

int Transport::count = 0;

class Car : public Transport {
    int doors;

public:
    Car(const std::string& name, double maxSpeed, int doors)
        : Transport(name, maxSpeed), doors(doors) {}

    ~Car() {}

    void move() const override {
        std::cout << "Car \"" << name << "\" (" << doors
             << " doors) drives along the road at up to "
             << maxSpeed << " km/h." << std::endl;
    }
};

class Airplane : public Transport {
    double maxAltitude;

public:
    Airplane(const std::string& name, double maxSpeed, double maxAltitude)
        : Transport(name, maxSpeed), maxAltitude(maxAltitude) {}

    ~Airplane() {}

    void move() const override {
        std::cout << "Airplane \"" << name << "\" flies through the air at altitudes up to "
             << maxAltitude << " m and speeds up to "
             << maxSpeed << " km/h." << std::endl;
    }
};

class Ship : public Transport {
    double displacement;

public:
    Ship(const std::string& name, double maxSpeed, double displacement)
        : Transport(name, maxSpeed), displacement(displacement) {}

    ~Ship() {}

    void move() const override {
        std::cout << "Ship \"" << name << "\" (displacement " << displacement
             << " t) sails across the water at up to "
             << maxSpeed << " km/h." << std::endl;
    }
};

int main() {
    {
        Car car("Toyota Camry", 210, 4);
        Airplane plane("Airbus A320", 850, 12000);
        Ship ship("Titanic II", 40, 52000);

        std::vector<Transport*> transports = { &car, &plane, &ship };

        std::cout << "=== Transport info ===" << std::endl;
        for (const Transport* t : transports) {
            t->printInfo();
        }

        std::cout << "\n=== Virtual method call via base class pointer ===" << std::endl;
        for (const Transport* t : transports) {
            t->move();
        }
    }

    return 0;
}