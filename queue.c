#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int items[MAX_SIZE];
int front = -1, rear = -1;

int isEmpty() {
    return (front == -1 && rear == -1);
}

int isFull() {
    return (rear == MAX_SIZE - 1);
}

void enqueue(int value) {
    if (isFull()) {
        printf("Queue is full!\n");
    } else {
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear++;
        }
        items[rear] = value;
        printf("Enqueued: %d\n", value);
    }
}

int dequeue() {
    int item;
    if (isEmpty()) {
        printf("Queue is empty!\n");
        return -1;
    } else {
        item = items[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front++;
        }
        printf("Dequeued: %d\n", item);
        return item;
    }
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", items[i]);
        }
        printf("\n");
    }
}

int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);

    display();

    dequeue();
    dequeue();

    display();

    return 0;
}
