#include <iostream>

using namespace std;

class Complex
{
    double real, imag;

public:
    Complex() { real = 0; imag = 0; }
    Complex operator - (const Complex& c);
    Complex(double r, double i) { real = r; imag = i; }
    void print();
};

Complex Complex::operator - (const Complex& c)
{
    return Complex(real - c.real, imag - c.imag);
}

void Complex::print() {
    cout << real << "+" << imag << "i";
}

int main() {
    Complex c1(1,4);
    Complex c2(3,7);
    c1.print();
    cout << " minus ";
    c2.print();
    cout << "equals ";
    (c1-c2).print();
    cout << endl;
    return 0;
}