#include <iostream>
#include "Time.h"
using namespace std;

void Time::print() const
{
    cout << hour << ":" << minute << ":" << second << endl;
}