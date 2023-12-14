#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void input(T arr[], int n)
{
    cout << "Input: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}

template <typename T>
void sort(T arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;

        for (int j = i + 1; j < n; ++j)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        swap(arr[i], arr[minIndex]);
    }
}

template <typename T>
void output(T arr[], int n)
{
    cout << "Output: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cout << "Size of Array: ";
    cin >> n;

    int x[n];
    input<int>(x, n);
    sort<int>(x, n);
    output<int>(x, n);

    float y[n];

    input<float>(y, n);
    sort<float>(y, n);
    output<float>(y, n);
    return 0;
}