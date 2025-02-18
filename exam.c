#include <stdio.h>
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
int Partition(int a[],int n,int L,int U){
    int i=L,j=U;
    int piviot=a[L];
    while(i<j){
       while(a[i]<=piviot){
           i++;
       }
         while(a[j]>piviot){
              j--;
         }
        if(i<j){
                swap(&a[i],&a[j]);
            }
    }
    swap(&a[L],&a[j]);
    return j;
}
quicksort(int a[],int n,int L,int U){
    if(L<U){
        int j=Partition(a,n,L,U);
        quicksort(a,n,L,j-1);
        quicksort(a,n,j+1,U);
    }
}
int merge(int a[],int n,int L,int U){
    int i=L,j=U;
    int mid=(L+U)/2;
    while(i<=mid && j<=U){
        if(a[i]<a[j]){
            i++;
        }
        else{
            j++;
        }
    }
    return i;
}
void mergesort(int a[],int n,int L,int U){
    if(L<U){
        int mid=merge(a,n,L,U);
        mergesort(a,n,L,mid-1);
        mergesort(a,n,mid,U);
    }
}

int main(){
    int arr[5]={5,4,3,2,1};
    quicksort(arr,5,0,4);
    mergesort(arr,5,0,4);
    return 0;
}