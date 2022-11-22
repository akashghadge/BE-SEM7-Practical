#include <bits/stdc++.h>
using namespace std;
int partition(vector<int> &arr, int lb, int ub)
{
    int pivot = arr[lb], start = lb, end = ub;
    while (start < end)
    {
        while (pivot >= arr[start])
            start++;
        while (pivot < arr[end])
            end--;
        if (start < end)
            swap(arr[start], arr[end]);
    }
    swap(arr[lb], arr[end]);
    return end;
}
void quick_sort(vector<int> &arr, int lb, int ub)
{
    if (lb < ub)
    {
        int loc = partition(arr, lb, ub);
        quick_sort(arr, lb, loc - 1);
        quick_sort(arr, loc + 1, ub);
    }
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (auto val : arr)
        cout << val << " ";
    cout << endl;
    quick_sort(arr, 0, n - 1);
    for (auto val : arr)
        cout << val << " ";
}