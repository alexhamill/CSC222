struct Fraction{
    int numerator;
    int denominator;
    //constructors
    Fraction(std::string);
    Fraction();
    Fraction(int, int);
    Fraction(int);
    //functions
    void print () const;
    std::string to_string() const;
    Fraction operator*(Fraction) const;
    Fraction operator/(Fraction) const;
};
int gcd(int, int);
