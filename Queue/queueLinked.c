// Implementation of queue using a linked list

#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

void enqueue(int x)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;
    if(front == NULL && rear == NULL) {
        front = rear = temp;
        return;
    }
    rear->next = temp;
    rear = temp;
}

void dequeue()
{
    struct Node* temp = front;
    if(front == NULL && rear == NULL) {
        printf("Queue is empty\n\n");
        return;
    }
    if(front == rear) {
        front = rear = NULL;
    }
    else {
        front = front->next;
    }
    free(temp);
}

int Front()
{
    if(front == NULL && rear == NULL) {
        printf("Queue is empty\n\n");
        return -1;
    }
    printf("%d\n\n", front->data);
    return front->data;
}

void print()
{
    if(front == NULL && rear == NULL) {
        printf("Queue is empty\n\n");
        return;
    }
    printf("List elements: \n");
    struct Node* temp = front;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n\n");
}

int main()
{
    print();
    enqueue(1);
    print();
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    print();
    dequeue();
    print();
    enqueue(6);
    enqueue(7);
    Front();
    enqueue(8);
    enqueue(9);
    enqueue(10);
    enqueue(11);
    print();
}