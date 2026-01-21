#include <iostream>
using namespace std;

struct Node{
    int data ;
    Node *NextAdd;
};

Node *list = NULL;
Node *currPosition;

void insert(int value) {
    //1st memory assign
    Node *curr_memory = (Node*) malloc(sizeof(Node));
    curr_memory->data = value;
    if (list == NULL) {
    list = curr_memory;
        curr_memory->NextAdd = list;
}
    else {
        currPosition = list;
        while (currPosition->NextAdd !=list) {
            currPosition = currPosition->NextAdd;
        }
        currPosition->NextAdd = curr_memory;
        curr_memory->NextAdd = list;

    }
}

void display() {
    Node* curr = list;
    while (curr->NextAdd != list) {
        cout << curr->data << " ";
        curr = curr->NextAdd;
    }
cout<<curr->data;
    cout << endl;

    if (list == NULL) {
        cout<<"no element found in this list\n";
    }
}

void search(int data) {
    Node *current = list;
    do {
        if (current->data == data) {
            cout<<"found";
            return;
        }
        else {
            current = current->NextAdd;
        }
    }
    while (current->NextAdd !=list);
cout<<"Not found";
}


void Delete(int data){
    Node* previous =  list;
    Node* current  = list->NextAdd;
    Node* temp;

    if (previous->data == data) {
        cout<<"deleted\n";
        temp = list;
        while (temp->NextAdd !=list) {
            temp = temp->NextAdd;
        }

        list  = current  ;

        free(previous);

        temp->NextAdd = list;
        return;

    }
    while (current->NextAdd != list) {
        if (current->data == data) {
            previous->NextAdd = current->NextAdd;
            free(current);
            cout<<"deleted";
            return;
        }
        current  = current->NextAdd;
        previous = previous -> NextAdd;

    }
    if (current->NextAdd ==list && current->data == data) {
        previous->NextAdd = list;
        free(current);
        cout<<" found element : "<< data<<endl;
        return;
    }
    cout<<"NOt found element : "<< data<<endl;
}
int main() {
int choice;

    bool start  = true;
    while (start) {
        cout<<"Enter the choice bhaii \n"
              "1) insert "
              "2) search "
              "3) display "
              "4) delete "
              "5) quit"<<endl;
        cin>>choice;
        switch( choice){
            case 1 :
                cout<<"inter the input number : ";
                int numm;
                cin>>numm;
                insert(numm);
                break;
            case 2:
                cout<<"inter the search  number : ";
                int num1;
                cin>>num1;
                search(num1);
                break;
            case 3:
                display();
                break;
            case 4 :
                cout<<"inter the deleted  number : \n";
                int num2;
                cin>>num2;
                Delete(num2);
                break;
            case 5 :
                cout<<"dhanaywaad apka bhut bhut... allah hafiz\n";
                start = false;
                break;
            default:
                cout<<"sahi select kr bhaiii\n";
        }
    }

insert(5);
    insert(7);
    insert(10);
    // display();
    // search(12);
Delete(10);
    display();
}