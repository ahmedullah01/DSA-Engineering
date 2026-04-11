#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* Queue = NULL;

// enqueue
void Enqueue(int data){
    Node* newNode = new Node{data, NULL};

    if (Queue == NULL) {
        Queue = newNode;
        return;
    }

    Node* temp = Queue;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// dequeue
int Dequeue(){
    if (Queue == NULL) return -1;

    Node* temp = Queue;
    int val = temp->data;
    Queue = Queue->next;
    delete temp;

    return val;
}

void Dequeuevoid(){
    if (Queue == NULL) return ;

    Node* temp = Queue;
   
    Queue = Queue->next;
    delete temp;

   
}

void ReverseK(int k){

    if (k == 0 || Queue == NULL) {
        return;
    }

    int val = Dequeue();   // front remove

    ReverseK(k - 1);       // recursion

    Enqueue(val);          // back insert
}

void ReverseWholeQueue() {
   if(Queue == NULL) {
       return;
   }
  int val = Dequeue(); // front remove
ReverseWholeQueue(); // recursion
Enqueue(val); // back insert

}


void display() {
    Node* temp = Queue;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Enqueue(1);
    Enqueue(2);
    Enqueue(3);
    Enqueue(4);
    Enqueue(5);

    int k = 2;
    ReverseK(k);

        // ReverseWholeQueue();
    
        display();  
    // Print the reversed queue
    // while (Queue != NULL) {
    //     cout << Dequeue() << " ";
    }
    // cout << endl;

  
