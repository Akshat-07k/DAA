#include <stdio.h>
#define MAX_SIZE 100
int main()
{
    FILE *file;
    file = fopen("data.txt", "wb"); // Open the file in binary write mode
    if (file == NULL)
    {
        perror("Error opening file");
        return 1;
    }

    int array[MAX_SIZE] = {10, 20, 30, 40, 50}; // Example array

    fwrite(array, sizeof(int), MAX_SIZE, file);

    fclose(file);

    // Read and print the data
    file = fopen("data.txt", "rb"); // Open the file in binary read mode
    if (file == NULL)
    {
        perror("Error opening file");
        return 1;
    }

    int readArray[MAX_SIZE];
    size_t bytesRead = fread(readArray, sizeof(int), MAX_SIZE, file);

    fclose(file);

    for (int i = 0; i < bytesRead; i++)
    {
        printf("%d\n", readArray[i]);
    }

    // int n;
    // scanf(" %d ", &n);
    // int arr[n];

    // for (int i = 0; i < n; i++)
    //     scanf(" %d", &arr[i]);

    // for (int i = 0; i < n; i++)
    // {
    //     int j = i;
    //     while (j > 0 && arr[j] < arr[j - 1])
    //     {

    //         int temp = arr[j];
    //         arr[j] = arr[j - 1];
    //         arr[j - 1] = temp;
    //         j--;
    //     }
    // }

    // for (int i = 0; i < n; i++)
    //     printf("%d ", arr[i]);

    return 0;
}