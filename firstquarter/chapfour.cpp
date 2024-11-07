#include <iostream>
using namespace std;

int main() {
    int i = 4;
    float f = 5;
    bool b1 = i < f, b2 = f < i, b3 = f / i < i / f;
    if (b3)
        if (b2)
            i += 1;
        else
            i += 2;
    else if (b1)
        i += 3;
    else
        i += 4;
    cout << i << endl;

    return 0;
}
