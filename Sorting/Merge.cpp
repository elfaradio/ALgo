#include <bits/stdc++.h>
using namespace std;

void Merge(int arr[], int low, int mid, int high)
{
    int temp[high - low + 1], l = low, r = mid + 1, k = 0;

    while (l <= mid && r <= high)
    {
        if (arr[l] <= arr[r])
        {
            temp[k++] = arr[l++];
        }

        else
        {
            temp[k++] = arr[r++];
        }
    }
    while (l <= mid)
    {
        temp[k++] = arr[l++];
    }

    while (r <= high)
    {
        temp[k++] = arr[r++];
    }

    for (int i = 0; i < k; i++)
    {
        arr[low + i] = temp[i];
    }
}

void MergeSort(int arr[], int low, int high)
{
    if (low >= high)
    {
        return;
    }

    int mid = (low + high) / 2;
    MergeSort(arr, low, mid);
    MergeSort(arr, mid + 1, high);
    Merge(arr, low, mid, high);
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

    MergeSort(a, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}
