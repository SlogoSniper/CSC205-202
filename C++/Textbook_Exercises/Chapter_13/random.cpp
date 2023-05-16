#include <iostream>
#include <cstdlib>
#include "random.h"
using namespace std;

int random_between(int l, int h) {
    srand((unsigned) time(NULL));
    return l+rand()%(h-l+1);
}

int main() {
    cout << "Random number between 4 and 9: ";
    cout << random_between(4,9) << endl;
    return 0;
}