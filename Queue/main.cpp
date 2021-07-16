// Implementation of queue using an array

#include<iostream>

using namespace std;

#define N 10

class Queue
{
private:
	int A[N];
	int front, rear;
public:
	Queue()
	{
		front = -1;
		rear = -1;
	}

	bool isEmpty() {
		// checks if queue has at least one element
        return (front == -1 && rear == -1);
    }

    int Front() {
		// returns the 1st element in the queue (from front to back)
        if(front == -1) return -1;
        return A[front];
    }

    bool isFull() {
		// checks if there is space available for one more element in the queue (since the queue is an array of fixed size)
        return ((rear + 1) % N == front);
    }

    int enqueue(int x) {
		// adds an element to the back of the queue
		// case 1: queue has no elements
        if(isEmpty()) {
            front = rear = 0;
        }
		// case 2: queue has no space left for the enqueue operation
        else if(isFull()) {
            cout << "Can't enqueue because queue is full" << endl;
            return -1;
        }
		// case 3: queue has elements and space to add one more in the back of the queue
        else {
            rear = (rear + 1) % N;
        }
        A[rear] = x;
        return 0;
    }

    int dequeue() {
		// removes an element from the front of the queue
		// case 1: queue has no elements
        if(isEmpty()) {
            cout << "Can't dequeue because queue is empty" << endl;
            return -1;
        }
		// case 2: there is only one element in the queue, so it will be empty after the dequeue operation
        else if(front == rear) {
            front = rear = -1;
        }
		// case 3: element can be removed from the front of the queue normally
        else {
            front = (front + 1) % N;
        }
        return 0;
    }

    void print() {
		// prints all elements in the queue
        int count = (rear + N - front) % N + 1;
        cout << "Elements\n";
        for(int i = 0; i < count; i++) {
            int index = (front + i) % N;
            cout << A[index] << " ";
        }
        cout << "\n\n";
    }
};

int main() {
    // test queue implementation
    Queue Q;

    if(Q.isEmpty()) {
        cout << "True\n" << endl;
    }
    else {
        cout << "False\n" << endl;
    }
    Q.enqueue(1);
    if(Q.isEmpty()) {
        cout << "True\n" << endl;
    }
    else {
        cout << "False\n" << endl;
    }
    if(Q.isFull()) {
        cout << "True\n" << endl;
    }
    else {
        cout << "False\n" << endl;
    }
    Q.enqueue(2);
    Q.enqueue(3);
    Q.enqueue(4);
    Q.enqueue(5);
    Q.print();
    Q.dequeue();
    Q.print();
    Q.enqueue(6);
    Q.enqueue(7);
    cout << Q.Front() << endl;
    cout << "\n";
    Q.enqueue(8);
    Q.enqueue(9);
    Q.enqueue(10);
    Q.enqueue(11);
    Q.print();
    if(Q.isFull()) {
        cout << "True" << endl;
    }
    else {
        cout << "False" << endl;
    }
}