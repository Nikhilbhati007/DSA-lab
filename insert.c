#include <stdio.h>
int main(){
    int a[50],size,pos,num,i;
    printf("Enter the size of the array: ");
    scanf("%d",&size);
    if(size>50){
        printf("Array size exceeded");
        return 0;
    }
    else{
        printf("Enter the position you want to insert the element: ");
        scanf("%d",&pos);
        for(i=size;i>=pos;i--){
            a[i]=a[i-1];
        }
        printf("Enter the number you want to insert: ");
        scanf("%d",&num);
        a[pos-1]=num;
    }
    for 
    return 0;
}