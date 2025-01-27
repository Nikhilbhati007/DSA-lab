#include <stdio.h>

void Exp_Mov_avg(int arr[], int n, int size_win) {
    int B[n - size_win + 1];
    float EMA = arr[0]; 
    float a = 2.0 / (size_win + 1); 
    
    for (int i = 1; i < n; i++) {
        EMA = (arr[i] * a) + EMA * (1 - a);
        if (i >= size_win - 1) {
            B[i - size_win + 1] = EMA;
        }
    }
    for (int i = 0; i<n-size_win+1; i++) {
        printf("%d ", B[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        printf("Enter the element: ");
        scanf("%d", &arr[i]);
    }
    int size_win;
    printf("Enter the size of the window: ");
    scanf("%d", &size_win);

    Exp_Mov_avg(arr, n, size_win);
    return 0;
}
