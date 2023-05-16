#include <iostream>
using namespace std;

struct Time {
    int hour, minute;
    double second;


    Time(int h, int m, double s);
    Time(double secs);

    void increment(double secs);

    void print() const;
    bool after(const Time& time2) const;
    Time add(const Time& t2) const;
    double convert_to_seconds() const;
};

Time::Time(int h, int m, double s) {
    hour = h;
    minute = m;
    second = s;
}

Time::Time(double secs) {
    hour = (int(secs) / 3600);
    minute = (int(secs) / 60 - 60 * (int(secs) / 3600));
    second = (secs - 60 * (int(secs) / 60));
}

void Time::increment(double s) {
    hour += (int(s) / 3600);
    minute += (int(s) / 60 - 60 * (int(s) / 3600));
    second += (s - 60 * (int(s) / 60));
}

void Time::print() const {
    cout << hour << ":" << minute << ":" << second << endl;
}

bool Time::after(const Time& time2) const {
    if (hour > time2.hour) return true;
    if (hour < time2.hour) return false;
  
    if (minute > time2.minute) return true;
    if (minute < time2.minute) return false;

    return (second > time2.second);
}

Time Time::add(const Time& t2) const {
	return Time(convert_to_seconds() + t2.convert_to_seconds());
}

double Time::convert_to_seconds() const {
    return ((hour * 60) + minute) * 60 + second;
}

int main()
{
    Time current_time(11, 28, 35.0);
    current_time.increment(500.0);
    current_time.print();
    cout << endl;

    Time my_time(5, 12, 15.0);
    Time done_time = current_time.add(my_time);
    done_time.print();
    cout << endl;

    if (done_time.after(current_time)) {
        cout << "The time will run out after it starts" << endl;
    }
    return 0;
}
