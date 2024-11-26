#include <iostream>

class Animal {
public:
    virtual void Speak() = 0;

    virtual ~Animal() {
    };
};

class Dog : public Animal {
public:
    void Speak() override {
        std::cout << "Dog Speak" << std::endl;
    }
};

class Cat : public Animal {
public:
    void Speak() override {
        std::cout << "Cat Speak" << std::endl;
    }
};

class Car {
public:
    std::string brand;
    int speed;

    void Start() {
        std::cout << "Car Speak" << std::endl;
    }

    void Stop() {
        std::cout << "Car Stop" << std::endl;
    }

    void Accelerate() {
        std::cout << "Car Accelerate" << std::endl;
    }
};

class ElectroCar : public Car {
public:
    void Charge() {
        std::cout << "ElectroCar Charge" << std::endl;
    }
};

class Account {
    void First() {
        std::cout << "Account First" << std::endl;
    }
};

class SavingsAccount : public Account {
    void Second() {
        std::cout << "SavingsAccount First" << std::endl;
    }
};

class CheckingAccount : public Account {
    void Five() {
        std::cout << "CheckingAccount Five" << std::endl;
    }
};

int main() {
    Animal *d = new Dog;
    Animal *c = new Cat;

    d->Speak();
    c->Speak();

    auto *e = new ElectroCar;
    e->Start();
    e->Stop();
    e->Accelerate();
    e->Charge();
}
