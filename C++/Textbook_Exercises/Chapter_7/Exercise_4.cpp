#include <iostream>
#include <string>
using namespace std;


int letter_appears(string str, char letter){
    int index = 0;
    int count = 0;

    while (index < str.length() - 1){
        if (str.find(letter, index) == -1){
            return count;
        } else {
            if (str[index] == letter){
                count += 1;
            }
            index += 1;
        }
    }
    return count + 1;
}



int main(){
    int x = letter_appears("Mississippi", 'i');

    cout << x << endl;

    return 0;
}