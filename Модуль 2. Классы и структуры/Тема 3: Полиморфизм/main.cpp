#include <iostream>
#include <ostream>

class Shape {
public:
    virtual void Print() = 0;
    virtual ~Shape() {}
};

class Rectangle : public Shape {
public:
    void Print() override {
        std::cout << "Rectangle" << std::endl;
    }
};

class Circle : public Shape {
public:
    void Print() override {
        std::cout << "Circle" << std::endl;
    }
};

class Payment {
public:
    virtual void Pay() = 0;
    virtual ~Payment() {}
};

class PayPal : public Payment {
public:
    void Pay() override {
        std::cout << "PayPal" << std::endl;
    }
};

class CreditCard : public Payment {
public:
    void Pay() override {
        std::cout << "CreditCard" << std::endl;
    }
};

void Pay(Payment& p) {
    p.Pay();
}

int main() {
    PayPal plp;
    CreditCard cred;

    Pay(plp);
    Pay(cred);
}
