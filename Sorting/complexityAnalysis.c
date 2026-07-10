#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

bool verifySort(int arr[], int size)
{
    for(int i = 0; i < size - 1; i++)
    {
        if(arr[i] > arr[i + 1])
        {
            return false;
        }
    }

    return true;
}

// Array generators

int* generateRandom(int size)
{
    int *arr = malloc(size * sizeof(int));

    if(arr == NULL)
    {
        printf("Memory Allocation Failed!\n");
        exit(1);
    }

    for(int i = 0; i < size; i++)
    {
        arr[i] = rand();
    }

    return arr;
}

int* generateAscending(int size)
{
    int *arr = malloc(size * sizeof(int));

    if(arr == NULL)
    {
        printf("Memory Allocation Failed!\n");
        exit(1);
    }

    for(int i = 0; i < size; i++)
    {
        arr[i] = i + 1;
    }

    return arr;
}

int* generateDescending(int size)
{
    int *arr = malloc(size * sizeof(int));

    if(arr == NULL)
    {
        printf("Memory Allocation Failed!\n");
        exit(1);
    }

    for(int i = 0; i < size; i++)
    {
        arr[i] = size - i;
    }

    return arr;
}

// Sorting Algorithms

void bubbleSort(int arr[], int size)
{
    for(int i = 0; i < size - 1; i++)
    {
        bool swapped = false;

        for(int j = 0; j < size - i - 1; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }

        if(!swapped)
            break;
    }
}

void insertionSort(int arr[], int size)
{
    for(int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

void selectionSort(int arr[], int size)
{
    for(int i = 0; i < size - 1; i++)
    {
        int minIndex = i;

        for(int j = i + 1; j < size; j++)
        {
            if(arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        swap(&arr[i], &arr[minIndex]);
    }
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];

    int i = low - 1;

    for(int j = low; j < high; j++)
    {
        if(arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);

    return i + 1;
}

void quickSort(int arr[], int low, int high)
{
    if(low < high)
    {
        int pivotIndex = partition(arr, low, high);

        quickSort(arr, low, pivotIndex - 1);

        quickSort(arr, pivotIndex + 1, high);
    }
}

void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int leftArray[n1];
    int rightArray[n2];

    for(int i = 0; i < n1; i++)
    {
        leftArray[i] = arr[left + i];
    }

    for(int j = 0; j < n2; j++)
    {
        rightArray[j] = arr[mid + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while(i < n1 && j < n2)
    {
        if(leftArray[i] <= rightArray[j])
        {
            arr[k] = leftArray[i];
            i++;
        }
        else
        {
            arr[k] = rightArray[j];
            j++;
        }

        k++;
    }

    while(i < n1)
    {
        arr[k] = leftArray[i];
        i++;
        k++;
    }

    while(j < n2)
    {
        arr[k] = rightArray[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right)
{
    if(left >= right)
        return;

    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid);

    mergeSort(arr, mid + 1, right);

    merge(arr, left, mid, right);
}

void heapify(int arr[], int size, int index)
{
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if(left < size && arr[left] > arr[largest])
    {
        largest = left;
    }

    if(right < size && arr[right] > arr[largest])
    {
        largest = right;
    }

    if(largest != index)
    {
        swap(&arr[index], &arr[largest]);

        heapify(arr, size, largest);
    }
}

void heapSort(int arr[], int size)
{
    for(int i = size / 2 - 1; i >= 0; i--)
    {
        heapify(arr, size, i);
    }
    for(int i = size - 1; i > 0; i--)
    {
        swap(&arr[0], &arr[i]);

        heapify(arr, i, 0);
    }
}

int main()
{
    // Test different array sizes
    for (int size = 8000; size <= 36000; size += 4000)
    {
        printf("Array Size: %d\n", size);

        // Generate Array
        int *arr = generateRandom(size);

        // Start Timer
        clock_t start = clock();

        // Apply Sort
        heapSort(arr, size);

        // Stop Timer
        clock_t end = clock();

        // Calculate Execution Time
        double executionTime = (double)(end - start) / CLOCKS_PER_SEC;

        // Verify Correctness
        if (verifySort(arr, size))
        {
            printf("Array is sorted successfully.\n");
        }
        else
        {
            printf("Sorting failed!\n");
        }

        printf("Execution Time: %.6f seconds\n", executionTime);
        printf("Execution Time: %.3f milliseconds\n", executionTime * 1000);

        // Free Memory
        free(arr);
    }

    return 0;
}