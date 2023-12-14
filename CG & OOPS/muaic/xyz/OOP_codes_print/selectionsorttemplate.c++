
#include <iostream>
using namespace std;
int n;
#define size 10
template <typename T>
void sel(T A[size])
{
    int i, j, min;
    T temp;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (A[j] < A[min])
                min = j;
        }
        temp = A[i];
        A[i] = A[min];
        A[min] = temp;
    }
    cout << "\nSorted array:";
    for (i = 0; i < n; i++)
    {
        cout << " " << A[i];
    }cout<<endl;
}

int main()
{
    int A[size];
    float B[size];
    int i;
    int ch;
    do
    {
        cout << "1. Int Values"<<endl;
        cout << "2. Float Values"<<endl;
        cout<<  "3. Exit"<<endl;
        cout << "\nEnter your choice : "<<endl;
        cin >> ch;

        switch (ch)
        {
      case 1:
        cout << "\nEnter total no of int elements :";
        cin >> n;
        cout << "\nEnter int elements :";
        for (i = 0; i < n; i++)
        {
            cin >> A[i];
        }
        sel(A);
        break;
	  
	  case 2:
	  	cout<<"enter total no of float element : "<<endl;
	  	cin>>n;
	  	cout<<"enter the elements : "<<endl;
	  	for (i =0; i<n; i++){
	  		cin>>B[i];
	  	}
        sel(B);
        break;

        default:
            return 0;    
        }
    } while (ch != 3);

    return 0;
}
