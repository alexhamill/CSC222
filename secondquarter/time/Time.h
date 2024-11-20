#include <string>
#include <vector>
using namespace std;

struct Time {
    int hour;
    int minute;
    double second;

    void print() const;
    void increment(double);
    double convert_to_seconds() const;
    double secsuntill(Time) const;
    double minsuntill(Time) const;
    double hoursuntill(Time) const;
    Time(double secs);
    string to_string() const;
    Time();
    Time(int,int);
    Time(int,int,double);
};