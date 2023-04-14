// Cannot have a function as a part of an expression when the function is not an int
// Can have a function as a part of an expression when it is an int
#include <iostream>
using namespace std;

int myFunction()
{
    return 7;
}

int main()
{
    cout << "First Line." << endl;
    cout << myFunction() + 7 << endl;
    cout << "Second Line." << endl;
    return 0;
}

