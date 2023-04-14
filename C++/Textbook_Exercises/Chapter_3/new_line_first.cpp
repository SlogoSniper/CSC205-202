
#include <iostream>
#include <math.h>
using namespace std;

// File will not compile with newLine being defined after main
// Compiles and runs if newLine is before main

void newLine()
{
    cout << endl;
}

int main()
{
    cout << "First Line." << endl;
    newLine();
    cout << "Second Line." << endl;
    return 0;
}

