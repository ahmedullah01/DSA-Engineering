#include <iostream>
using namespace std;

// Doubly Linked List Node
struct Node {
    Node *prevAdd;
    int data;
    Node *NextAdd;
};

Node *list = NULL;   // head pointer

// 🔹 Insert at end
void insert(int value) {
    Node *newNode = new Node();   // allocate memory
    newNode->data = value;
    newNode->prevAdd = NULL;
    newNode->NextAdd = NULL;

    // If list empty
    if (list == NULL) {
        list = newNode;
        return;
    }

    // Traverse to last node
    Node *curr = list;
    while (curr->NextAdd != NULL)
        curr = curr->NextAdd;

    curr->NextAdd = newNode;
    newNode->prevAdd = curr;
}

// 🔹 Search element
void search(int value) {
    Node *curr = list;
    while (curr != NULL) {
        if (curr->data == value) {
            cout << "Value Found!\n";
            return;
        }
        curr = curr->NextAdd;
    }
    cout << "Value Not Found!\n";
}

// 🔹 Print list forward
void printList() {
    Node* curr = list;
    cout << "List: ";
    while (curr != NULL) {
        cout << curr->data << " <-> ";
        curr = curr->NextAdd;
    }
    cout << "NULL\n";
}

// 🔹 Delete node
void Delete(int value) {
    if (list == NULL) return;

    Node *curr = list;

    // If first node
    if (curr->data == value) {
        list = curr->NextAdd;
        if (list != NULL) list->prevAdd = NULL;
        delete curr;
        return;
    }

    while (curr != NULL && curr->data != value)
        curr = curr->NextAdd;

    if (curr == NULL) {
        cout << "Value not found!\n";
        return;
    }

    // Adjust pointers
    if (curr->NextAdd != NULL)
        curr->NextAdd->prevAdd = curr->prevAdd;

    curr->prevAdd->NextAdd = curr->NextAdd;
    delete curr;
}

// 🔹 Count occurrences
void multipleOccurence() {
    Node* currentI = list;

    while (currentI != NULL) {
        int count = 1;
        bool check = false;

        Node* prevJ = list;

        while (prevJ != currentI) {
            if (prevJ->data == currentI->data) {
                check = true;
                break;
            }
            prevJ = prevJ->NextAdd;
        }

        if (!check) {
            Node* nextJ = currentI->NextAdd;
            while (nextJ != NULL) {
                if (currentI->data == nextJ->data)
                    count++;
                nextJ = nextJ->NextAdd;
            }
            cout << "Count of " << currentI->data << " is: " << count << endl;
        }
        currentI = currentI->NextAdd;
    }
}

// 🔹 Sorted insertion
void insertionorder(int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->prevAdd = NULL;
    newNode->NextAdd = NULL;

    if (list == NULL || val < list->data) {
        newNode->NextAdd = list;
        if (list != NULL) list->prevAdd = newNode;
        list = newNode;
        return;
    }

    Node* curr = list;
    while (curr->NextAdd != NULL && curr->NextAdd->data < val)
        curr = curr->NextAdd;

    newNode->NextAdd = curr->NextAdd;
    if (curr->NextAdd != NULL)
        curr->NextAdd->prevAdd = newNode;

    curr->NextAdd = newNode;
    newNode->prevAdd = curr;
}

int main() {


    int choice;
    int value;

    do {
        cout << "\n--- Doubly Linked List Menu ---\n";
        cout << "1. Insert at End\n";
        cout << "2. Insert in Order\n";
        cout << "3. Delete\n";
        cout << "4. Search\n";
        cout << "5. Print List\n";
        cout << "6. Count Occurrences\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";

        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                insert(value);
                break;

            case 2:
                cout << "Enter value: ";
                cin >> value;
                insertionorder(value);
                break;

            case 3:
                cout << "Enter value: ";
                cin >> value;
                Delete(value);
                break;

            case 4:
                cout << "Enter value: ";
                cin >> value;
                search(value);
                break;

            case 5:
                printList();
                break;

            case 6:
                multipleOccurence();
                break;

            case 0:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 0);

    return 0;
}
