#include <iostream>
#include <cctype>
using namespace std;

string stringToUpper(string str){
    string new_str;
    for (int i = 0; i < str.length(); i++) { 
        new_str += toupper(str[i]);
    }
    return new_str;
}

string stringToLower(string str){
    string new_str;
    for (int i = 0; i < str.length(); i++) { 
        new_str += tolower(str[i]);
    }
    return new_str;
}

int main()
{
    cout << stringToUpper("allcaps") << endl; cout << stringToLower("ALLLOWER") << endl;
    return 0;
}
