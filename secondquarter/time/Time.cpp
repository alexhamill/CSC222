#include <iostream>
#include "Time.h"
using namespace std;

void Time::print() const
{
    cout << hour << ":" << minute << ":" << second << endl;
}
void Time::increment(double secs)
{
    second += secs;
    while (second >= 60.0) {
        second -= 60.0;
        minute += 1;
    }
    while (minute >= 60) {
        minute -= 60;
        hour += 1;
    }
}
double Time::convert_to_seconds() const
{
    int minutes = hour * 60 + minute;
    double seconds = minutes * 60 + second;
    return seconds;
}