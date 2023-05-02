#include<ctime>
#include <cstdlib>
#include <iostream>
using namespace std;

int main()
{
    cout << "Let's generate 10 random numbers." << endl;
    for (int i = 1; i < 11; i++) {
        cout << "Random number " << i << ": " << rand() % 10 << endl;
    }

    return 0;
}
