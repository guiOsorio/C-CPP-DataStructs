// linked-list implementation of a stack

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* link;
};

struct Node* top = NULL;

void Push(int x) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node*));
    temp->data = x;
    temp->link = top;
    top = temp;
}

void Pop() {
    struct Node* temp;
    if(top == NULL) return;
    temp = top;
    top = top->link;
    free(temp);
}

int main(void) {
    Push(2);
    printf("%i\n", top->data);
    Push(5);
    printf("%i\n", top->data);
    Pop();
    printf("%i\n", top->data);
}