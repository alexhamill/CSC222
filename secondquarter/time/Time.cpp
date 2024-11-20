#include <iostream>
#include "Time.h"
using namespace std;
#include <string>

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
double Time::secsuntill(Time secondtime) const{
    double sec1 = convert_to_seconds();
    double sec2 = secondtime.convert_to_seconds();
    return sec2 - sec1;
}
double Time::minsuntill(Time secondtime) const{
    return secsuntill(secondtime)/60;
}
double Time::hoursuntill(Time secondtime) const{
    return minsuntill(secondtime)/60;
}
Time::Time(double secs){
    hour = int(secs / 3600.0);
    secs -= hour * 3600.0;
    minute = int(secs / 60.0);
    secs -= minute * 60;
    second = secs;
}
string Time::to_string() const{
    string value = std::to_string(hour) + ":";
    if(minute<10){
        value +="0";
    }
    value += std::to_string(minute) + ":";
    if(second<10){
        value +="0";
    }
    value += std::to_string(int(second));
    return value;
}
Time::Time(){
    hour = 0;
    second = 0;
    minute = 0;
}
Time::Time(int h, int m){
 hour = h;
 minute = m;
}
Time::Time(int h,int m,double s){
    hour = h;
    minute = m;
    second = s;
}