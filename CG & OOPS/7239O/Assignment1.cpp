#include <bits/stdc++.h>
using namespace std;

class Complex
{
public:
    double real, imag;

    Complex(double r = 0, double i = 0)
    {
        real = r;
        imag = i;
    }

    Complex operator+(Complex &obj)
    {
        Complex result;
        result.real = real + obj.real;
        result.imag = imag + obj.imag;
        return result;
    }

    Complex operator*(Complex &obj)
    {
        Complex result;
        result.real = real * obj.real - imag * obj.imag;
        result.imag = real * obj.imag + imag * obj.real;
        return result;
    }
};

istream &operator>>(istream &input, Complex &c)
{
    cout << "Enter real part: ";
    input >> c.real;
    cout << "Enter imaginary part: ";
    input >> c.imag;
    return input;
}

ostream &operator<<(ostream &output, Complex &c)
{
    if (c.imag > 0)
        output << c.real << " + " << c.imag << "i" << '\n';
    else
        output << c.real << " - " << abs(c.imag) << "i" << '\n';

    return output;
}

int main()
{
    cout << "Enter First Complex number:\n";
    Complex Input1;
    cin >> Input1;

    cout << "Enter Second Complex number:\n";
    Complex Input2;
    cin >> Input2;

    cout << "First Complex number: " << Input1 << '\n';
    cout << "Second Complex number: " << Input2 << '\n';

    Complex add = Input1 + Input2;
    cout << "Sum: " << add << '\n';

    Complex mul = Input1 * Input2;
    cout << "Product: " << mul << '\n';

    return 0;
}
