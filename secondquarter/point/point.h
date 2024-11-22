#include <string>
#include <vector>
using namespace std;

struct Point{
    int x;
    int y;

    Point();
    Point(int);
    Point(int,int);
    Point operator+(const Point&);

};
