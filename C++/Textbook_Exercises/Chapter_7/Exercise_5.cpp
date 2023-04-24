#include <iostream>
using namespace std;

int main()
{
    string suffix = "ack";

    char letter = 'J';
    while (letter <= 'Q') {
        if (letter == 'O' || letter == 'Q'){
            cout << letter << 'u' << suffix << endl;    
        } else {
            cout << letter + suffix << endl;
        }
        
        letter++;
    }
    return 0;
}
