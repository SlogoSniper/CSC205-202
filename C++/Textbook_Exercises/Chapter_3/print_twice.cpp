// Will not work because trying to pass non-char into a char argument

#include <iostream>
using namespace std;

void print_twice(char phil) {
    cout << phil << phil << endl;
}

int main() {
    print_twice('a');
    print_twice(3);
    print_twice(3.23);
    print_twice("hello");
    return 0;
}