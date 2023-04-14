// Will not work because trying to pass non-char into a char argument
// Will work if function is changed to string input and then convert non-strings into strings

#include <iostream>
using namespace std;

void print_twice(string phil) {
    cout << phil << phil << endl;
}

int main() {
    print_twice("a");
    print_twice(to_string(3));
    print_twice(to_string(3.23));
    print_twice("hello");
    return 0;
}