#include <iostream>
using namespace std;

class Rational {
private:
    int numerator;
    int denominator;

    int gcd(int a, int b);

public:
    Rational();                         
    Rational(int num, int denom);       

    void setData(int num, int denom);
    void display() const;

    Rational add(const Rational& r2) const;
    Rational subtract(const Rational& r2) const;
    Rational multiply(const Rational& r2) const;
    Rational divide(const Rational& r2) const;
};

Rational::Rational() {
    numerator = 0;
    denominator = 1;
}

Rational::Rational(int num, int denom) {
    setData(num, denom);
}

int Rational::gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void Rational::setData(int num, int denom) {
    if (denom == 0) {
        cout << "Denominator cannot be zero. Defaulting to 1." << endl;
        denom = 1;
    }

    int common = gcd(abs(num), abs(denom));
    numerator = num / common;
    denominator = denom / common;

    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }
}

void Rational::display() const {
    cout << numerator << "/" << denominator << endl;
}

Rational Rational::add(const Rational& r2) const {
    int num = numerator * r2.denominator + r2.numerator * denominator;
    int denom = denominator * r2.denominator;
    return Rational(num, denom);
}

Rational Rational::subtract(const Rational& r2) const {
    int num = numerator * r2.denominator - r2.numerator * denominator;
    int denom = denominator * r2.denominator;
    return Rational(num, denom);
}

Rational Rational::multiply(const Rational& r2) const {
    int num = numerator * r2.numerator;
    int denom = denominator * r2.denominator;
    return Rational(num, denom);
}

Rational Rational::divide(const Rational& r2) const {
    int num = numerator * r2.denominator;
    int denom = denominator * r2.numerator;
    return Rational(num, denom);
}

int main() {
    Rational r1, r2, result;

    cout << "Enter numerator and denominator for first rational number: ";
    int n1, d1;
    cin >> n1 >> d1;
    r1.setData(n1, d1);

    cout << "Enter numerator and denominator for second rational number: ";
    int n2, d2;
    cin >> n2 >> d2;
    r2.setData(n2, d2);

    cout << "\nFirst Rational: ";
    r1.display();

    cout << "Second Rational: ";
    r2.display();

    result = r1.add(r2);
    cout << "\nSum: ";
    result.display();

    result = r1.subtract(r2);
    cout << "Difference: ";
    result.display();

    result = r1.multiply(r2);
    cout << "Product: ";
    result.display();

    result = r1.divide(r2);
    cout << "Quotient: ";
    result.display();

    return 0;
}

