#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string num_to_str(double num) {
    stringstream str_s;
    string mystr;
    str_s << num;
    str_s >> mystr;
    return mystr;
}


struct Time {
    int hour, minute;
    double second;

    string to_string();
};

string Time::to_string() {
    Time time = *this;
    string mystr;
    if (time.hour < 10) {
        mystr += "0";
    }
    mystr += num_to_str(time.hour)+":";
    if (time.minute < 10) {
        mystr += "0";
    }
    mystr += num_to_str(time.minute)+":";
    if (time.second < 10.0) {
        mystr += "0";
    }
    mystr += num_to_str(time.second);
    return mystr;
}

int main() {
    Time lunch = {1,35,4.0};
    cout << lunch.to_string() << endl;
    return 0;
}