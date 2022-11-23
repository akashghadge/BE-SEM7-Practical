#include <bits/stdc++.h>
using namespace std;
void merge(int a[], int p, int q, int r)
{
    int b[5]; // same size of a[]
    int i = p, j = q + 1, k = 0;
    while (i <= q && j <= r)
    {
        if (a[i] < a[j])
            b[k++] = a[i++]; // same as b[k]=a[i]; k++; i++;
        else
            b[k++] = a[j++];
    }

    while (i <= q)
        b[k++] = a[i++];
    while (j <= r)
        b[k++] = a[j++];

    for (i = r; i >= p; i--)
        a[i] = b[--k]; // copying back the sorted list to a[]
}
void mergeSort(int a[], int p, int r)
{
    int q;
    if (p < r)
    {
        q = (p + r) / 2;
        mergeSort(a, p, q);
        mergeSort(a, q + 1, r);
        merge(a, p, q, r);
    }
}


// function to print the array
void printArray(int a[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {32, 45, 67, 2, 7};
    int len = sizeof(arr) / sizeof(arr[0]);

    printf("Given array: \n");
    printArray(arr, len);

    // calling merge sort
    mergeSort(arr, 0, len - 1);

    printf("\nSorted array: \n");
    printArray(arr, len);
}