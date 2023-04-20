#include <iostream>
using namespace std;
#include <math.h>

int main(){
    int x = 2;
    int x_pow = 0;

    while (x_pow < 17) {
        cout << x << "^" << x_pow << " is: " << pow(x, x_pow)<< endl;
        x_pow++;
    }

    return 0;
}