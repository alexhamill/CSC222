#include <iostream>
using namespace std;

int main() {

    int x = 3, y = x++, z = ++x;
    cout << (z - x < y - x ? 5 : 6) <<  endl;
    return 0;
}