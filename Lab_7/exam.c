#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// QuickSort Partition Function
int Partition(int a[], int L, int U) {
    int i = L, j = U;
    int pivot = a[L];
    while (i < j) {
        while (a[i] <= pivot && i < U) i++;
        while (a[j] > pivot) j--;
        if (i < j) {
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[L], &a[j]);
    return j;
}

// QuickSort Recursive Function
void quicksort(int a[], int L, int U) {
    if (L < U) {
        int j = Partition(a, L, U);
        quicksort(a, L, j - 1);
        quicksort(a, j + 1, U);
    }
}

// Merge two sorted subarrays (L to mid and mid+1 to U)
void merge(int a[], int L, int mid, int U) {
    int i = L, j = mid + 1, k = 0;
    int temp[U - L + 1];

    while (i <= mid && j <= U) {
        if (a[i] < a[j]) {
            temp[k++] = a[i++];
        } else {
            temp[k++] = a[j++];
        }
    }
    while (i <= mid) temp[k++] = a[i++];
    while (j <= U) temp[k++] = a[j++];

    for (i = L, k = 0; i <= U; i++, k++) {
        a[i] = temp[k];
    }
}

// MergeSort Recursive Function
void mergesort(int a[], int L, int U) {
    if (L < U) {
        int mid = (L + U) / 2;
        mergesort(a, L, mid);
        mergesort(a, mid + 1, U);
        merge(a, L, mid, U);
    }
}

// Utility function to print array
void printArray(int a[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main() {
    int arr[5] = {5, 4, 3, 2, 1};

    // Uncomment one of the sorting algorithms to test
    quicksort(arr, 0, 4);
    // mergesort(arr, 0, 4);

    printf("Sorted array: ");
    printArray(arr, 5);

    return 0;
}
