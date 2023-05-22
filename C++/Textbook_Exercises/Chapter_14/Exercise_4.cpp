#include <iostream>
#include <math.h>

using namespace std;

class Complex
{
    double real, imag;

public:
    Complex() { real = 0; imag = 0; }
    Complex operator - (const Complex& c);
    Complex operator / (const Complex& c);
    Complex(double r, double i) { real = r; imag = i; }
    friend ostream& operator<<(ostream& os, const Complex& c);
    double abs();
};

ostream& operator<<(ostream& os,const Complex& c) {
    os << c.real;
    if (c.imag>=0) {
        os << "+";
    }
    os << c.imag << "i";
    return os;
}


int main() {
    Complex c1(3,-4);
    cout << c1 << endl;
    return 0;
}