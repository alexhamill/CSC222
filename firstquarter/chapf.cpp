 
    #include <iostream>
using namespace std;

int main() {

int a = 4, b = 3, c = 2;
if (a > 0) {
    b -= 4;
    if (b > 0) {
        if (c > 0)
            c++;
        if (c <= 3)
            c--;
    }
if (b < 0)
    a--;
}
c = a + b + c;
cout << c;
return 0;
}