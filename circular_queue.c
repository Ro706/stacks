#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

int items[MAX_SIZE];
int front = -1, rear = -1;

int isFull() {
    return (front == (rear + 1) % MAX_SIZE);
}

int isEmpty() {
    return (front == -1 && rear == -1);
}

void enqueue(int value) {
    if (isFull()) {
        printf("Queue is full!\n");
    } else {
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % MAX_SIZE;
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
            front = (front + 1) % MAX_SIZE;
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
        int i = front;
        while (i != rear) {
            printf("%d ", items[i]);
            i = (i + 1) % MAX_SIZE;
        }
        printf("%d\n", items[rear]);
    }
}

int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);

    display();

    dequeue();
    dequeue();

    display();

    enqueue(6);
    enqueue(7);

    display();

    return 0;
}
