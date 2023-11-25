/*Aim 06-Assignment 06: Stack is a very important data structure. Implement the following operations on
stack
A. void push(int *stack, int *top, int val);
B. void pop(int *stack, int *top);
C. int isEmpty(int *stack, int *top);
D. int isFull(int *stack, int *top);
E. int topElement(int *stack, int *top);
F. void traversal(int *stack, int *top);*/
#include <stdio.h>
/*Name-Pranita dadhe
PRN-22070521099
Aim 06-Assignment 06: Stack is a very important data structure. Implement the following operations on
stack
A. void push(int *stack, int *top, int val);
B. void pop(int *stack, int *top);
C. int isEmpty(int *stack, int *top);
D. int isFull(int *stack, int *top);
E. int topElement(int *stack, int *top);
F. void traversal(int *stack, int *top);*/
#include <stdio.h>
#define SIZE 100
void initialize(int *top) {
    *top = -1;
}
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
int main() {
    int stack[SIZE];
    int top;
    initialize(&top);
    traversal(stack, &top);
    push(stack, &top, 1);
    traversal(stack, &top);
    push(stack, &top, 5);
    traversal(stack, &top);
    push(stack, &top, 50);
    traversal(stack, &top);
    printf("Top element: %d\n", topElement(stack, &top));
    pop(stack, &top);
    traversal(stack, &top);
    pop(stack, &top);//1 left
    traversal(stack, &top);
    push(stack, &top, 25);
    traversal(stack, &top);
    push(stack, &top, 52);
    traversal(stack, &top);
    push(stack, &top, 30);
    traversal(stack, &top);
    printf("Top element: %d\n", topElement(stack, &top));
    return 0;
}


