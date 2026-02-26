#include <iostream>
using namespace std;

struct SNode{
    string seatnum;
    SNode* Snext;
};
// Doubly Linked List Node
struct CNode {
    string Coursedata;
    CNode *NextAdd;
    SNode* studentList;
};



CNode *list = NULL;   // head pointer
CNode* CurrentPosition ;// for  course traverse
SNode* CurrentPosition2 ; // for student traverse

void CourseInsert(string coursenum){

    CNode* Course_CM =  new CNode();//current memory

Course_CM->Coursedata = coursenum;
Course_CM->NextAdd = NULL;
Course_CM->studentList = NULL;

if(list == NULL ){
    list = Course_CM;
}else{
 CurrentPosition  = list;// for traverse
    while(CurrentPosition->NextAdd!=NULL){
CurrentPosition = CurrentPosition->NextAdd;
    }
    CurrentPosition->NextAdd = Course_CM;
}
}


void printList() {
    CurrentPosition  = list;// for traverse
    cout << "List: \n | ";
    while (CurrentPosition != NULL) {
        cout << CurrentPosition->Coursedata ;
        CurrentPosition2 = CurrentPosition->studentList;
        while(CurrentPosition2!= NULL){
            cout<<"-> "<<CurrentPosition2->seatnum;
            CurrentPosition2 = CurrentPosition2->Snext;
        }
        CurrentPosition = CurrentPosition->NextAdd;
        cout<< "\n"" | ";
    }
    cout << "NULL\n";
}

void InsertStudentInCourse(string coursenum , string EnterSeatNum  ){

    //sb say phelay wo course dhondhay gay 
 CurrentPosition  = list;
 while(  CurrentPosition->Coursedata!=coursenum && CurrentPosition!=NULL){
    cout<<"fgd";
CurrentPosition = CurrentPosition->NextAdd;
 }
 if(CurrentPosition == NULL){
    cout<<"Not Found CourseNum";
    return;

 }else{

    SNode* Student =  new SNode();//current memory
Student->seatnum = EnterSeatNum;
Student->Snext = NULL;

CurrentPosition2 = CurrentPosition->studentList;//traverstion starrt
if(CurrentPosition2 == NULL ){
     CurrentPosition->studentList = Student;
     cout<<"sfdfvf";
}
else{
    while(CurrentPosition2->Snext!=NULL){
CurrentPosition2 = CurrentPosition2->Snext;
    }
    CurrentPosition2->Snext = Student;
}

 }

}

int main() {
    int choice;
    string coursenum, seatnum;

    do {
        cout << "1. Insert Course" << endl;
        cout << "2. Insert Student in Course" << endl;
        cout << "3. Print List" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter course number: ";
                cin >> coursenum;
                CourseInsert(coursenum);
                break;{}
            case 2:
                cout << "Enter course number: ";
                cin >> coursenum;
                cout << "Enter seat number: ";
                cin >> seatnum;
               InsertStudentInCourse(coursenum, seatnum);
                break;
            case 3:
                printList();
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}

