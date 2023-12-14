#include <bits/stdc++.h>
using namespace std;

class Complex
{
public:
    double real, img;

    Complex(double r = 0, double i = 0)
    {
        real = r;
        img = i;
    }

    // operator overloading

    Complex operator+(Complex &obj)
    {
        Complex res;
        res.real = real + obj.real;
        res.img = img + obj.img;
        return res;
    }

    Complex operator*(Complex obj)
    {
        Complex res;
        res.real = real * obj.real - img * obj.img;
        res.img = real * obj.img + img * obj.real;
        return res;
    }
};

istream &operator>>(istream &input, Complex &c)
{
    cout << "Enter real part:";
    input >> c.real;
    cout << "Enter imaginary part:";
    input >> c.img;
    return input;
}

ostream &operator<<(ostream &output, Complex &c)
{
    if (c.img > 0)
    {
        output << c.real << " + " << c.img << "i\n";
    }
    else
    {
        output << c.real << " - " << c.img << "i\n";
    }
    return output;
}

int main()
{
    Complex c1, c2;
    cout << "Enter first complex number\n";
    cin >> c1;

    cout << "Enter second complex number\n";
    cin >> c2;

    cout << "First complex number: " << c1 << endl;
    cout << "Second complex number: " << c2 << endl;

    Complex add = c1 + c2;
    cout << "Addition:" << add;
    Complex mul = c1 * c2;
    cout << "Multiplication:" << mul;
}