#include <bits/stdc++.h>
using namespace std;

void Merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;
    int l = low;
    int r = mid + 1;
    while (l <= mid and r <= high)
    {
        if (arr[l] <= arr[r])
        {
            temp.push_back(arr[l++]);
        }
        else
        {
            temp.push_back(arr[r++]);
        }
    }
    while (l <= mid)
    {
        temp.push_back(arr[l++]);
    }
    while (r <= high)
    {
        temp.push_back(arr[r++]);
    }
    for (int i = low; i <= high; i += 1)
    {
        arr[i] = temp[i - low];
    }
}
void MergeSort(vector<int> &arr, int low, int high)
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
    vector<int> a(n);
    for (int i = 0; i < n; i += 1)
    {
        cin >> a[i];
    }
    MergeSort(a, 0, n - 1);

    for (auto c : a)
    {
        cout << c << " ";
    }
}
