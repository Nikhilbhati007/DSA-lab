#include <stdio.h>
int main(){
    int a[50],size,pos,i;
    printf("Enter the size of the array: ");
    scanf("%d",&size);
    if (size>50){
        printf("Array exceeded");
    }
    else{
        printf{"Enter the postion that you want to delete: "};
        scanf("%d",&pos);
        for(i=pos-1;i<size-1;i++){
            a[i]=a[i+1];
        }
        }
    for(i=0;i<size-1;i++){  
        printf("%d",a[i]);
    }
    return 0;
}