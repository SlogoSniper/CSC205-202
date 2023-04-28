#include<iostream>
using namespace std;


struct Time {
    int hour, minute;
    double second;
};

double convert_to_seconds(const Time& t){
    int minutes = t.hour * 60 + t.minute;
    double seconds = minutes * 60 + t.second;

    return seconds;
}

Time make_time(double secs){
    Time time;
    time.hour = int(secs / 3600.0);
    secs -= time.hour * 3600.0;
    time.minute = int(secs / 60.0);
    secs -= time.minute * 60;
    time.second = secs;

    return time;
}

void increment(Time& time, double secs){
    double seconds = convert_to_seconds(time);
    seconds += secs;
    time = make_time(seconds);
}

int main(){
    Time time = {3, 55, 23};
    increment(time, 124);
    cout << time.hour << "." << time.minute << "." << time.second << endl;
}

