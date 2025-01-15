#include <stdio.h>
int main(){
    int a[50],size,i,pos,num;
    printf("Enter the size of the array: ");
    scanf("%d",&size);
    printf("Enter the elements of the array: ");
    for(i=0;i<size;i++){
        scanf("%d",&a[i]);
    }
    printf("Enter the position where you want to insert the element: ");
    scanf("%d",&pos);
    printf("Enter the element you want to insert: ");
    scanf("%d",&num);
    for(i=size-1;i>=pos-1;i--){
        a[i+1]=a[i];
    }
    a[pos-1]=num;
    size++;
    printf("The array after insertion is: ");
    for(i=0;i<size;i++){
        printf("%d ",a[i]);
    }
    return 0;
}