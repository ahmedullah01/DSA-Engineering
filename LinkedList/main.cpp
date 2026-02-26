#include <algorithm> // Standard algorithms header
#include <iostream>  // For input/output
#include <Stdlib.h>  // For malloc/free
using namespace std;

// Node structure for singly linked list
struct Node{
    int data;       // Store the value
    Node *next ;    // Pointer to next node
};

Node *List = NULL;           // Head pointer of the linked list
Node* current_Position ;      // Temporary pointer (used in some functions)

// Function to insert node at the end
void insert(int value ) {
    // Allocate memory for new node
    Node* current_memory = (Node*) malloc(sizeof(Node));

    current_memory ->data = value;   // Store the value in node
    current_memory -> next = NULL;   // Next pointer is NULL initially

    if (List == NULL) {               // If list is empty
        List = current_memory;        // New node becomes head
    }
    else {
        Node* current_Position = List; // Start from head

        if (current_Position->next == NULL) { // Only one node in list
            current_Position -> next  = current_memory ; // Add new node
        }
        else {
            while (current_Position->next != NULL) { // Traverse to last node
                current_Position =current_Position -> next;
            }
            current_Position->next = current_memory; // Link last node to new node
        }
    }
}

// Function to display all nodes
void display() {
    Node* current_Position = List;     // Start from head
    while (current_Position != NULL )  {  // Traverse till end
        int data  =  current_Position ->data; // Get node data
        cout<<data<<endl;               // Print node data
        current_Position = current_Position ->next; // Move to next node
    }
}

// Function to search for a value
void search(int value)   {
    int count = 0 ;                    // To track position
    bool found = false;                // Flag if value found
    Node* current_Position = List;     // Start from head
    while (current_Position != NULL && !found)  { // Traverse till found or end
        count++;
        int data  =  current_Position ->data; // Get node data
        if (data == value) {             // If match found
            found = true;
            cout<<"found: "<<data<<" at position of node :"<<count; // Print position
        }
        current_Position = current_Position ->next; // Move to next
    }
    if (found == false) {
        cout<<"not found ";              // If value not present
    }
}

// Function to delete a node with given value
void Delete(int num){
    bool found = false;                  // Flag if node found
    bool checkerdata = false;            // Another flag for safety
    Node* current_Position = List;       // Start from head
    Node* pervious_position ;            // To store previous node

    if (current_Position->data == num) { // If head node is the one to delete
      List = current_Position->next;     // Update head
    }
    else {
        while (current_Position != NULL && !found) { // Traverse list
            int data  =  current_Position ->data;
            if (data == num) {           // Node found
                checkerdata = true;
                found = true;
                break;
            }
            pervious_position = current_Position;     // Keep previous node
            current_Position = current_Position ->next; // Move next
        }

        if (checkerdata) {                // If node to delete is found
            current_Position = current_Position -> next; 
            pervious_position -> next = current_Position; // Link previous to next
        }
        if (found == false) {
            cout<<"not found ";          // If node not found
        }
    }
}

// ------------------- Main Function with Menu -------------------
int main() {
    int choice, value; // User choice and input value

    while(true){ // Loop until user quits
        cout << "\n===== LINKED LIST MENU =====\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Display\n";
        cout << "4. Search\n";
        cout << "5. Quit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice){
            case 1: // Insert node
                cout << "Enter value to insert: ";
                cin >> value;
                insert(value);
                break;

            case 2: // Delete node
                cout << "Enter value to delete: ";
                cin >> value;
                Delete(value);
                break;

            case 3: // Display all nodes
                display();
                break;

            case 4: // Search node
                cout << "Enter value to search: ";
                cin >> value;
                search(value);
                break;

            case 5: // Quit program
                cout << "Program terminated.\n";
                return 0;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    }
}