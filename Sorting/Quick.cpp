#include <bits/stdc++.h>
using namespace std;

int Partition(int arr[], int low, int high)
{
    int pivot = arr[low], i = low, j = high;
    while (i < j)
    {
        while (arr[i] <= pivot && i <= high - 1)
        {
            i++;
        }

        while (arr[j] > pivot && j >= low + 1)
        {
            j--;
        }

        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[low], arr[j]);
    return j;
}

void qsort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = Partition(arr, low, high);
        qsort(arr, low, pi - 1);
        qsort(arr, pi + 1, high);
    }
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    qsort(a, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}
