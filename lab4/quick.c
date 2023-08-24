// #include<iostream>
// using namespace std;
#include <stdio.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int l, int h)
{
    int pivot = arr[l];
    int i = l, j = h;

    do
    {
        do
        {
            i++;
        } while (arr[i] < pivot && (i < h));
        do
        {
            j--;
        } while (arr[j] > pivot);

        if (i < j)
        {
            swap(&arr[i], &arr[j]);
            i++;
            j--;
        }
        else
            i++;

    } while (i <= j);
    // swap(arr[l],arr[j])
    arr[l] = arr[j];
    arr[j] = pivot;

    return j;
}

void quick(int arr[], int l, int h)
{
    int j;
    if (l < h)
    {
        j = partition(arr, l, h);
        quick(arr, l, j);
        quick(arr, j + 1, h);
    }
}
int main()
{
    // int n, choice;
    // cout << " Entre size : ";
    // cin >> n;
    int arr[] = {5, 4, 3, 2, 1};
    // for (int i = 0; i < n; i++)
    // cin >> arr[i];

    quick(arr, 0, 5);

    for (int i = 0; i < 5; i++)
        printf(" %d", arr[i]);
    return 0;
}
