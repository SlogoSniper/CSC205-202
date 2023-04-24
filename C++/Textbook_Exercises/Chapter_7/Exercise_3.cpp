#include <iostream>
using namespace std;


int letter_appears(string str, char letter){
    int count = 0;
    int index = 0;

    while (index < str.length()) {
        if (str[index] == letter) {
            count = count + 1;
        }
        index = index + 1;
    }
    
    return count;
}

int main(){
    int x = letter_appears("Mississippi", 'i');
    cout << x << endl;
    return 0;
}