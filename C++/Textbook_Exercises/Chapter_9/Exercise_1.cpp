#include<iostream>
using namespace std;

struct Time {
    int hour, minute;
    double second;
};

void reset(const Time& t1) // does not compile, cannot modify t1 as it is const
{

    t1.hour = 0;
    t1.minute = 0;
    t1.second = 0;
}

int main(){
    Time time = {3, 55, 23};
    reset(time);
    cout << time.hour << "." << time.minute << "." << time.second << endl;
}
