#include <iostream>
using namespace std;


void add(int a, int b)
{
cout << "sum = " << (a + b);
}

void add(double a, double b)
{
	cout << endl << "sum = " << (a + b);
}


int main()
{
    int a,b;
    cin>>a>>b;
    double c,d;
    cin>>c>>d;
	add(a,b);
	add(c,d);

	return 0;
}
