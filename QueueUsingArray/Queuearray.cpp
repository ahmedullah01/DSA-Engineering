#include <iostream>
using namespace std;

#define MAX 5

int queueArr[MAX];
int front = -1;
int rear = -1;

// Enqueue (Insert)
void enqueue(int value) {
    if (rear == MAX - 1) {
        cout << "Queue Overflow\n";
        return;
    }

    if (front == -1) {
        front = 0;
    }

    rear++;
    queueArr[rear] = value;
}

// Dequeue (Remove)
void dequeue() {
    if (front == -1 || front > rear) {
        cout << "Queue Underflow\n";
        return;
    }

    cout << "Deleted: " << queueArr[front] << endl;
    front++;

    // Reset queue when empty
    if (front > rear) {
        front = rear = -1;
    }
}

// Display Queue
void display() {
    if (front == -1) {
        cout << "Queue is Empty\n";
        return;
    }

    cout << "Queue: ";
    for (int i = front; i <= rear; i++) {
        cout << queueArr[i] << " ";
    }
    cout << endl;
}

// Main Function
int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();

    dequeue();
    display();

    enqueue(40);
    enqueue(50);
    display();

    enqueue(60); // Overflow case

    return 0;
}