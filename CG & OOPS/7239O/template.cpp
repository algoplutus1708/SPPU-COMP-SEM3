#include <iostream>
using namespace std;

template <typename T>
void rev(T arr[], int n)
{
    for (int i = 0; i < n / 2; i++)
    {
        swap(arr[i], arr[n - i - 1]);
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    rev(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    return 0;
}



