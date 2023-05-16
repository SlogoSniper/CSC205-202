#include <iostream>
using namespace std;

struct Time {
    int hour, minute;
    double second;

    double convert_to_seconds();
    void make_time(double secs);
    void increment(double secs);
};

double Time::convert_to_seconds() {
    return 3600*hour+60*minute+second;
}

void Time::make_time(double secs) {
    hour = secs/3600;
    minute = secs/60-60*hour;
    second = secs-60*minute-3600*hour;
}

void Time::increment(double secs)
{
    make_time(convert_to_seconds()+secs);
}

int main() {
    Time mytime = {20,59,3.0};
    cout << mytime.hour << ":" << mytime.minute << ":" << mytime.second << endl;
    cout << "45 seconds later..." << endl;
    mytime.increment(45);
    cout << mytime.hour << ":" << mytime.minute << ":" << mytime.second << endl;
    return 0;
}