#include <stdio.h>
int Mov_avg(int arr[],int n,int size_win){
    int B[n-size_win+1],sum=0;
    for(int i=0;i<=n-size_win;i++){
        for(int k=0;k<size_win;k++){
            sum=sum+arr[k+i];
        }
        float avg=sum/size_win;
        B[i]=avg;
        sum=0;}
    for(int i=0;i<n-size_win+1;i++){
        printf("%d ",B[i]);
    }
}
int main(){
    int n;
    printf("Enter the number of elements in the array:");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        printf("Enter the element:");
        scanf("%d",&arr[i]);
    }
    int size_win;
    printf("Enter the size of the window:");
    scanf("%d",&size_win);
    Mov_avg(arr,n,size_win);
    return 0;
}