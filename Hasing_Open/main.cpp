#include <iostream>
struct Node {
int value;
Node* next;
};


class QuadraticProbingWithInt {
public:
    Node* array[3] = {NULL};
    int flag[3]=  {false} ;

    void insert(int value) {
        Node* n = new Node();
        n->value = value;
        n->next = NULL;
        int index = value%3;
        if (flag[index] == false) // not fill
        {
            array[index] = n;//index pr milgai
            flag[index] = true;
        }else {
            Node* currentPosition = array[index];

            while (currentPosition->next != NULL) {
                currentPosition = currentPosition->next;
            }

            currentPosition->next = n;



        }

    }
    void display() {
        for (int i = 0; i < 3; i++) {

            std::cout << "Index " << i << " - ";

            if (array[i] == NULL) {
                std::cout << "NULL";
            }
            else {
                Node* current = array[i];

                while (current != NULL) {
                    std::cout << current->value;

                    if (current->next != NULL)
                        std::cout << " - ";

                    current = current->next;
                }
            }

            std::cout << std::endl;
        }
    }


    void search(int value) {
        int index= value%3;
        if (array[index]->value == value) {
            std::cout <<" index :"<<index;
            return;
        }
        int  i = 1;
        do {
            index = (value+i)%3;
            if (array[index]->value != value) {
                i++;
            }
            if (array[index]->value == value) {
                std::cout <<" index :"<<index;
                return;
            }
        }while (i!=3);
        std::cout<<"Not found :Sorry babeee";

    }
};


int main() {

QuadraticProbingWithInt* p = new QuadraticProbingWithInt();
    p->insert(22);
    p->insert(25);
p->display();
     }
