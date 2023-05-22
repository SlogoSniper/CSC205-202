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
    void print();
    double abs();
};

double Complex::abs() {
    return sqrt(real*real+imag*imag);
}

void Complex::print() {
    cout << real << "+" << imag << "i";
}

int main() {
    Complex c1(3,-4);
    cout << "|";
    c1.print();
    cout << "|=";
    cout << c1.abs();
    cout << endl;
    return 0;
}