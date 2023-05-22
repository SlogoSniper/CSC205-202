#include <iostream>

using namespace std;

class Complex
{
    double real, imag;

public:
    Complex() { real = 0; imag = 0; }
    Complex operator - (const Complex& c);
    Complex operator / (const Complex& c);
    Complex(double r, double i) { real = r; imag = i; }
    void print();
};

Complex Complex::operator / (const Complex& c)
{
    double A = real;
    double B = imag;
    double C = c.real;
    double D = c.imag;
    double newreal = (A*C+B*D)/(C*C+D*D);
    double newimag = (B*C-A*D)/(C*C+D*D);
    return Complex(newreal, newimag);
}

void Complex::print() {
    cout << real << "+" << imag << "i";
}

int main() {
    Complex c1(1,4);
    Complex c2(3,7);
    cout << "(";
    c1.print();
    cout << ")/(";
    c2.print();
    cout << ")=";
    (c1/c2).print();
    cout << endl;
    return 0;
}