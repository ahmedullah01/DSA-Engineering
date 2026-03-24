#include <iostream>

// Node structure for Queue
struct QueueNode{
    int data;       // store the value
    QueueNode* next; // pointer to next node
};

// Global pointers for Queue
QueueNode* Front = NULL;          // points to front of the queue
QueueNode* Rear = NULL;           // points to rear of the queue
QueueNode* currposition = NULL;   // temporary pointer for traversing

// Function to add element in queue
void EnQueue(int value) {
    QueueNode* newnode = new QueueNode(); // create new node
    newnode->data = value;                // assign data
    newnode->next = NULL;                 // next is NULL for new node
    if (Front == NULL ) {                 // if queue is empty
        Front = newnode;
        Rear = Front;                     // both front and rear point to first node
    }
    else {
        Rear->next  = newnode;           // link new node at rear
        Rear = Rear->next;               // move Rear pointer to new node
    }
}

// Function to display queue
void Display() {
    if (Front == NULL) {                  // check if queue is empty
        std::cout << "Beta, phelay kuch dalo to!\n";
    } else {
        currposition = Front;
        while(currposition != NULL) {    // traverse from front to rear
            std::cout << currposition->data << " -> ";
            currposition = currposition->next;
        }
        std::cout << "NULL\n";           // indicate end of queue
    }
}

// Function to remove element from queue
void Dequeue() {
    if (Front == NULL) {                  // if queue is empty
        std::cout << "Bagair kuch dalay kesay nikal sktay uncle!\n";
    } else {
        currposition = Front;             // temp pointer points to front
        Front = Front->next;              // move front to next node
        delete(currposition);             // free memory of removed node
        std::cout << "Deleted bae\n";
    }
}

// Interactive main function
int main() {
    char choice;
    int value;

    std::cout << "=== Queue Program ===\n";

    while(true) {
        std::cout << "\nOptions:\n";
        std::cout << "1. Enqueue\n";
        std::cout << "2. Dequeue\n";
        std::cout << "3. Display\n";
        std::cout << "q. Quit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if(choice == '1') {
            std::cout << "Enter value to enqueue: ";
            std::cin >> value;
            EnQueue(value);
        } else if(choice == '2') {
            Dequeue();
        } else if(choice == '3') {
            Display();
        } else if(choice == 'q' || choice == 'Q') {
            std::cout << "Exiting program...\n";
            break;
        } else {
            std::cout << "Invalid choice! Try again.\n";
        }
    }

    return 0;
}
