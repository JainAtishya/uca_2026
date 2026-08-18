#include <stdio.h>
#include <string.h>
#include <stddef.h>

void swap(void *a, void *b, size_t size)
{
    char temp[size];

    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b, temp, size);
}

void heapify(void *arr, int n, int i, size_t size,
             int (*cmp)(const void *, const void *))
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    void *current = (char *)arr + i * size;

    if (left < n)
    {
        void *leftValue = (char *)arr + left * size;

        if (cmp(leftValue, current) > 0)
        {
            largest = left;
        }
    }

    void *largestValue = (char *)arr + largest * size;

    if (right < n)
    {
        void *rightValue = (char *)arr + right * size;

        if (cmp(rightValue, largestValue) > 0)
        {
            largest = right;
        }
    }

    if (largest != i)
    {
        void *largestValue = (char *)arr + largest * size;

        swap(current, largestValue, size);

        heapify(arr, n, largest, size, cmp);
    }
}

void heapSort(void *arr, int n, size_t size,
              int (*cmp)(const void *, const void *))
{

    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i, size, cmp);
    }

    for (int i = n - 1; i > 0; i--)
    {
        void *first = arr;
        void *last = (char *)arr + i * size;

        swap(first, last, size);

        heapify(arr, i, 0, size, cmp);
    }
}

int cmpInt(const void *a, const void *b)
{
    int x = *(const int *)a;
    int y = *(const int *)b;

    if (x < y)
        return -1;
    if (x > y)
        return 1;

    return 0;
}

int cmpFloat(const void *a, const void *b)
{
    float x = *(const float *)a;
    float y = *(const float *)b;

    if (x < y)
        return -1;
    if (x > y)
        return 1;

    return 0;
}

int cmpDouble(const void *a, const void *b)
{
    double x = *(const double *)a;
    double y = *(const double *)b;

    if (x < y)
        return -1;
    if (x > y)
        return 1;

    return 0;
}


int main()
{
    int intArr[] = {10, 4, 8, 2, 15, 6};
    int intN = sizeof(intArr) / sizeof(intArr[0]);

    float floatArr[] = {5.5f, 2.2f, 9.1f, 1.4f, 7.3f};
    int floatN = sizeof(floatArr) / sizeof(floatArr[0]);

    double doubleArr[] = {4.25, 1.75, 8.50, 2.10, 6.30};
    int doubleN = sizeof(doubleArr) / sizeof(doubleArr[0]);

    heapSort(intArr, intN, sizeof(int), cmpInt);

    heapSort(floatArr, floatN, sizeof(float), cmpFloat);

    heapSort(doubleArr, doubleN, sizeof(double), cmpDouble);

    printf("Sorted integers: ");
    for (int i = 0; i < intN; i++)
    {
        printf("%d ", intArr[i]);
    }

    printf("\n");

    printf("Sorted floats: ");
    for (int i = 0; i < floatN; i++)
    {
        printf("%.2f ", floatArr[i]);
    }

    printf("\n");

    printf("Sorted doubles: ");
    for (int i = 0; i < doubleN; i++)
    {
        printf("%.2lf ", doubleArr[i]);
    }

    printf("\n");

    return 0;
}