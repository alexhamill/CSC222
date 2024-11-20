#include <iostream>
#include "Time.h"
using namespace std;

int main(){
    Time current_time = {7, 5, 6.5};
    Time secondtime = {8,5,8.5};
    current_time.print();
    current_time.print();
    cout << current_time.convert_to_seconds() << endl;;
    cout << secondtime.convert_to_seconds();
    cout << endl << "seconds " << current_time.secsuntill(secondtime)<< endl;
    cout << "minutes " << current_time.minsuntill(secondtime)<< endl;
    cout << "hours " << current_time.hoursuntill(secondtime)<< endl;
    return 0;
}
