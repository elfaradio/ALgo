#include <bits/stdc++.h>
using namespace std;

void Heapify(int arr[], int n, int i)
{
    int left = 2 * i + 1, right = 2 * i + 2, large = i;

    if (left < n && arr[left] > arr[large])
    {
        large = left;
    }

    if (right < n && arr[right] > arr[large])
    {
        large = right;
    }

    if (large != i)
    {
        swap(arr[i], arr[large]);
        Heapify(arr, n, large);
    }
}

void HeapSort(int arr[], int n)
{
    for (int i = (n / 2) - 1; i >= 0; i--)
    {
        Heapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        Heapify(arr, i, 0);
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

    HeapSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
