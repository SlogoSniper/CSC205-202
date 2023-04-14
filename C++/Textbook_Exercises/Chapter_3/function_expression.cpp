// Cannot have a function as a part of an expression when the function is not an int

#include <iostream>
using namespace std;

void newLine()
{
    cout << endl;
}

int main()
{
    cout << "First Line." << endl;
    newLine() + 7;
    cout << "Second Line." << endl;
    return 0;
}

