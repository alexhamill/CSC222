#include <iostream>
#include "point.h"
using namespace std;
#include <string>

Point::Point(){
    x=0;
    y=0;
}
Point::Point(double xin){
    x=xin;
}
Point::Point(double xin, double yin){
    x=xin;
    y=yin;
}
Point Point::operator+(const Point& second){
    Point result(x+second.x,y+second.y);
    return result;
}
string Point::to_string(){
    return "("+std::to_string(x)+", "+std::to_string(y)+")";
    }