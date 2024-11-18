#include <iostream>
#include "Time.h"
using namespace std;

int main(){
    Time current_time = {7, 5, 8.5};
    current_time.print();
    current_time.increment(1000);
    current_time.print();
    cout << current_time.convert_to_seconds();
    return 0;
}
