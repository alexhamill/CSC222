#include <string>
#include <vector>
using namespace std;

struct Point{
    double x;
    double y;

    Point();
    Point(double);
    Point(double,double);
    Point operator+(const Point&);
    string to_string();
    Point operator-(const Point&);
};
