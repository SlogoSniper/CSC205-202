#include <iostream>
using namespace std;

void compare(int a, int b) {
    if (a > b) {
        cout << "A is greater than B" << endl;
    } else if (a < b) {
        cout << "A is less than B" << endl;
    } else {
        cout << "A and B are equal" << endl;
    }
}

int main()
{
    compare(3, 4);
    compare(1450, 123);
    compare(5, 5);
    return 0;
}