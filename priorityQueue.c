#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int items[MAX_SIZE];
int priorities[MAX_SIZE];
int front = -1, rear = -1;

int isEmpty() {
    return (front == -1 && rear == -1);
}

int isFull() {
    return (rear == MAX_SIZE - 1);
}

void enqueue(int value, int priority) {
    if (isFull()) {
        printf("Queue is full!\n");
    } else {
	int i;
        if (isEmpty()) {
            front = rear = 0;
        } else {
            for (i = rear; i >= front; i--) {
                if (priority > priorities[i]) {
                    items[i+1] = items[i];
                    priorities[i+1] = priorities[i];
                } else {
                    break;
                }
            }
            rear++;
        }
        items[i + 1] = value;
        priorities[i + 1] = priority;
        printf("Enqueued: %d with priority %d\n", value, priority);
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
            printf("(%d, Priority: %d) ", items[i], priorities[i]);
        }
        printf("\n");
    }
}

int main() {
    enqueue(1, 2);
    enqueue(2, 1);
    enqueue(3, 3);
    enqueue(4, 2);

    display();

    dequeue();
    dequeue();

    display();

    return 0;
}


