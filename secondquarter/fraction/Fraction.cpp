#include <iostream>
#include "Fraction.h"
#include <string>
using namespace std;
Fraction::Fraction()
{
  numerator = 0;
  denominator = 1;
}
Fraction::Fraction(int n, int d)
{   
    int t = gcd(n,d);
    numerator = n/t;
    denominator = d/t;
}
void Fraction::print() const {
    cout<<numerator<<"/"<<denominator;
}

std::string Fraction::to_string() const{
    if(denominator==0){
        return "Can't divide by 0";
    }
    if(numerator==0){
        return "0";
    }
    if(denominator==1){
        return std::to_string(numerator);
    }
    return std::to_string(numerator)+"/"+std::to_string(denominator);
}

int gcd(int numerator,int denominator){
    int small = min(numerator, denominator);
    while(small > 1){
        if (numerator % small == 0 && denominator % small == 0)
            {
            return small;
            }
        small--;
    }
    return 1;
}