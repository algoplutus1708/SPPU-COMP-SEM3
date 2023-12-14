#include <bits/stdc++.h>
using namespace std;

class Base
{
public:
    int a, b;
    void addition(int a, int b)
    {
        cout << "The sum of the two numbers is " << a + b << endl;
        cout << "\n";
    }
};

class derived : public Base
{
public:
    void addition(int a, int b)
    {
        cout << "The sum of the two numbers multiplied by two is : " << a + b + a + b << endl;
    }
};


int main()
{
    derived obj;
    obj.addition(7, 9);
    int x = 10;
    char y = 'a';
    x = x + y;
    cout << x << "  is the value of x" << endl; 
  

  
    double z = 1.2;
    int sum = (int)z + 1;
   
    cout << sum << endl; 

    int k = 90;
    float b = 1.2;
    int c = b + k;   
    float n = b + k; 
    cout << c << " " << n << endl;

    int r = 10;
    string a = "990";
    int j = r + stoi(a); 
    cout<<j<<endl;
}