#include <iostream>
using namespace std;

struct Time {
    int hour, minute;
    double second;
    Time();
    double convert_to_seconds() const;
    Time(double secs);
    Time(int h, int m, double s);

public:
    Time operator + (const Time& t2);
    Time operator - (const Time& t2);
    friend ostream& operator << (ostream& os, const Time& t); 
};

Time::Time() {
    second = 0.0;
    minute = 0;
    hour = 0;
}

Time::Time(int h, int m, double s) {
    second = s;
    minute = m;
    hour = h;
}



double Time::convert_to_seconds() const {
    double seconds = hour * 3600 + minute * 60 + second;
    return seconds;
}

Time::Time(double secs)
{
    hour = int(secs / 3600.0);
    secs -= hour * 3600.0;
    minute = int(secs / 60.0);
    secs -= minute * 60;
    second = secs;
}

Time Time::operator + (const Time& t2)
{
    return Time(convert_to_seconds() + t2.convert_to_seconds());
}

Time Time::operator - (const Time& t2)
{
    return Time(convert_to_seconds() - t2.convert_to_seconds());
}

ostream& operator << (ostream& os, const Time& t) {
    if (t.hour<10) {
        os << "0";
    }
    os << t.hour << ":";
    if (t.minute<10) {
        os << "0";
    }
    os << t.minute << ":";
    if (t.second<10.0) {
        os << "0";
    }
    os << t.second;
    return os;
}

int main() {
    Time t1(31,41,59);
    Time t2(10000);
    Time t3(0,4,45);
    cout << "t1 is " << t1 << endl;
    cout << "t2 is " << t2 << endl;
    cout << "t3 is " << t3 << endl;
    cout << "t1 - t2 = " << t1-t2 << endl;
    cout << "t2 - t3 = " << t2-t3 << endl;
    cout << "t3 + t1 = " << t3+t1 << endl;
    return 0;
}