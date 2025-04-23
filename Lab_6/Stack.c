#include <stdio.h>
int n;
int arr[];
int top=-1;
void peek(){
    if(top==-1){
        printf("Underflow\n");
    }else{
        printf("The peek element:%d",arr[top]);
        printf("\n");
    }
}
void push(int x){
    if(top==n-1){
       printf("Overflow\n"); 
    }else{
        top++;
        arr[top]=x;
    }
}
void pop(){
    if(top==-1){
        printf("Underflow\n");
    }
    else{
        printf("pop out element:%d\n",arr[top]);
        top--;
    }    
}
void display(){
    if(top==-1){
        printf("Underflow\n");
    }
    else{
        for(int i=top;i>=0;i--){
            printf("%d ",arr[i]);
        }
        printf("\n");
    }
}
int main(){
    printf("enter the size of array:");
    scanf("%d",&n);
    int k,x;
    printf("enter the number push operation you want:");
    scanf("%d",&k);
    for(int i=1;i<=k;i++){
        printf("Enter the data:");
        scanf("%d",&x);
        push(x);
    }
    display();
    pop();
    display();
    peek();
    return 0;
}