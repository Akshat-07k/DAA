#include <stdio.h>
// Aim of the program: Write a program to implement Binary Search to give the position of
// leftmost appearance of the element in the array being searched. Display the number of
// comparisons made while searching.
// Input:
// Enter elements of the array: 2 3 7 7 7 11 12 12 20 50
// Output:
// 7 found at index position 2
// Number of comparisons: 3
int main()
{
    int n;
    printf(" Enter number of elements in the array :: ");
    scanf("%d", &n);
    int arr[n];
    printf(" Enter The elements of the array :: \n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int l = 0, r = n - 1, comp = 0;
    int val;
    printf(" Enter the required value :: ");
    scanf(" %d", &val);
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (val > arr[mid])
        {
            l = mid + 1;
            comp++;
        }
        else if (val < arr[mid])
        {
            r = mid - 1;
            comp++;
        }
        else
        {
            int i = mid;
            while (i > 0 && arr[i - 1] == val)
            {
                i--;
                comp++;
            }
            printf(" %d is index of leftMost %d \n", i, val);
            printf(" %d is total Comparision", comp);
            return 0;
        }
    }
    printf(" -1 ");
    return 0;
}