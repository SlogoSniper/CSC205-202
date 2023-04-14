
#include <iostream>
#include <math.h>
using namespace std;

/*Will not compile due to the newLine function coming after main*/

int main()
{
    cout << "First Line." << endl;
    newLine();
    cout << "Second Line." << endl;
    return 0;
}

void newLine()
{
    cout << endl;
}