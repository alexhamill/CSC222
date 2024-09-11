#include <iostream>
using namespace std;

int main() {
    int n = 2, m = n >> 1, p = m >> n, q = 1 << p, r = q << q;
    cout << m << p << q << r << endl;
    return 0;
}