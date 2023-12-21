#include <stdio.h>
#define SIZE 100
int stack[SIZE];
int top = -1;
int isFull(int *stack, int *top) {
    return (*top == SIZE - 1);
}
int isEmpty(int *stack, int *top) {
    return (*top == -1);
}
void push(int *stack, int *top, int x) {
    if (isFull(stack,top)) {
        printf("Stack is Full");
        return;
    }
    stack[++(*top)]=x;
}
void pop(int *stack, int *top) {
    if (isEmpty(stack,top)) {
        printf("Stack is empty");
        return;
    }
    (*top)--;
}
int topElement(int *stack, int *top) {
    if (isEmpty(stack,top)) {
        printf("Stack is empty\n");
        return *top;
    } else {
        return stack[*top];
    }
}
void traversal(int *stack, int *top) {
    if (isEmpty(stack,top)) {
        printf("Stack is empty\n");
        return;
        }
        for(int i=0;i<=(*top);i++){
                printf("%d ",stack[i]);
        }
        printf("\n");
}
void menu(int n){
          int input;
          switch (n){
                  case 1:
                           printf("\n");
                           printf("Enter a element you want to push:\n");
                           scanf("%d",&input);
                           push(stack,&top,input);
                           traversal(stack,&top);
                           break;
                   case 2:
                           pop(stack,&top);
                           traversal(stack,&top);
                           break;
                   case 3:
                           traversal(stack,&top);
                           break;
                   case 4:
                           printf("Top element: %d\n", topElement(stack, &top));
                           break;
                   default:
                           printf("bye!!! ");
                           break;

          }
}


int main() {
    int n=1 ;
    while(n){
         printf("1)push\n");
         printf("2)pop\n");
         printf("3)traversal\n");
         printf("4)top element\n");
         scanf("%d",&n);
         menu(n);
    }

    return 0;
}
