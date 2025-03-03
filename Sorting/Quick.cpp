#include <bits/stdc++.h>
using namespace std;
int Partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[low];
    int i = low;
    int j = high;
    while (i < j)
    {
        while (arr[i] <= pivot and i <= high - 1)
        {
            i++;
        }
        while (arr[j] > pivot and j >= low + 1)
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
vector<int> qsort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pi = Partition(arr, low, high);
        qsort(arr, low, pi - 1);
        qsort(arr, pi + 1, high);
    }
    return arr;
}
int main()
{

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i += 1)
    {
        cin >> a[i];
    }

    qsort(a, 0, n - 1);
    for (auto x : a)
    {
        cout << x << " ";
    }
}
