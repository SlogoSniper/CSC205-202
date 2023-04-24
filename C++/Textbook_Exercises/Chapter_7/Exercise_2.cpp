#include <iostream>
#include <string>
using namespace std;

int main(){
    string input;
    cin >> input;

    if (cin.good() == true){
        int index = input.length() - 1;

        while (index > -1){
            cout << input[index];
            index--;
        }
        cout << endl;
    } else {
        cout << "Bad input";
    }
}