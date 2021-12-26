#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}
int main()
{
    srand(time(0));
    int input;
    printf("Enter input size: ");
    scanf("%d", &input);
    int ArrayOne[input];
    for (int i = 0; i < input; i++)
    {
        ArrayOne[i] = rand() % 100 + 1;
    }
    int ArrayTwo[input];
    for (int i = 0; i < input; i++)
    {
        ArrayTwo[i] = ArrayOne[i];
    }

    clock_t t;
    t = clock();
    insertionSort(ArrayOne, input);
    t = clock() - t;
    double time_taken = ((double)t) / CLOCKS_PER_SEC;
    printf("\nInsertion sort took %f seconds to sort an array of input size %d\n", time_taken, input);

    clock_t u;
    u = clock();
    mergeSort(ArrayTwo, 0, input - 1);
    u = clock() - u;
    double time_takenMS = ((double)u) / CLOCKS_PER_SEC;
    printf("\nMerge sort took %f seconds to sort an array of input size %d\n", time_takenMS, input);
    
    if(time_takenMS > time_taken){
        printf("\nMerge sort took more time to sort the algo\n");
    }else{
        printf("\nInsertion sort took more time to sort the algo\n");
    }

    return 0;
}
