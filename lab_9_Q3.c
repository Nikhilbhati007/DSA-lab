#include <stdio.h>
int N;
int stack[N];
int top1=-1;
int top2=N;
void push1(int x){
    if(top2-top1==1){
        printf("Stack Overflow\n");
        return;
    }
    top1++;
    stack[top1]=x;
}
void push2(int x){
    if(top2-top1==1){
        printf("Stack Overflow\n");
        return;
    }
    top2--;
    stack[top2]=x;
}
int pop1(){
    if(top1==-1){
        printf("Stack Underflow\n");
        return -1;
    }
    int x=stack[top1];
    top1--;
    return x;
}
int pop2(){
    if(top2==N){
        printf("Stack Underflow\n");
        return -1;
    }
    int x=stack[top2];
    top2++;
    return x;
}
int main(){
return 0;
}