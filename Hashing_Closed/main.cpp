#include <iostream>
#include <cmath>

using namespace std;
//Linear probing
class LinearProbingWithInt {
public:

    int array[10] ;
    int flag[sizeof(array)]=  {false} ;

    void insert(int value) {
        int index = value%10;
        if (flag[index] == false) // not fill
        {
            array[index] = value; //index pr milgai
            flag[index] = true;
        }else {
            //agr nhi mili
            int i = 1;
            do {
                index = (value+i)%10; //index agay krkay banaya

                if (flag[index]  == true) {
                    i++;
                }
                if (flag[index] == false )//not fill
                {
                    //daldo value
                    array[index] = value;
                    flag[index] = true;
                    return;
                }

            }while (i !=10);
            std::cout << "array totally filledd";
        }

    }
    void display() {
        for (int i = 0 ;i < 10 ; i++) {
            std::cout << array[i] <<" ";
        }
    }
    void search(int value) {
        int index= value%3;
        if (array[index] == value) {
            std::cout <<" index :"<<index;
            return;
        }
        int  i = 1;
        do {
            index = (value+i)%3;
            if (array[index] != value) {
                i++;
            }
            if (array[index] == value) {
                std::cout <<" index :"<<index;
                return;
            }
        }while (i!=3);
        std::cout<<"Not found :Sorry babeee";

    }
};
class LinearProbingWithString {
public:

    std::string array[4] ;

    int flag[sizeof(array)]=  {false} ;

    void insert(string value) {
        //convert value into integer
        int index = ((int)value.back())%4 ;
        if (flag[index] == false) // not fill
        {
            array[index] = value; //index pr milgai
            flag[index] = true;
        }else {
            //agr nhi mili
            int i = 1;
            do {
              int index = ((int)value.back()+1)%4 ; //index agay krkay banaya

                if (flag[index]  == true) {
                    i++;
                }
                if (flag[index] == false )//not fill
                {
                    //daldo value
                    array[index] = value;
                    flag[index] = true;
                    return;
                }

            }while (i !=4);
            std::cout << "array totally filledd";
        }


    };
    void display() {
        for (int i = 0 ;i < 4 ; i++) {
            std::cout << array[i] <<" ";
        }
    }
        void search(string value) {
            int index = ((int)value.back())%4 ;
            if (array[index].compare(value) == 0)  {
                std::cout <<" index :"<<index;
                return;
            }
            int  i = 1;
            do {
                int index = ((int)value.back() +i)%4 ;
                if (array[index] != value) {
                    i++;
                }
                if (array[index] == value) {
                    std::cout <<" index :"<<index;
                    return;
                }
            }while (i!=4);
            std::cout<<"Not found :Sorry babeee";

        }
};
class QuadraticProbingWithInt {
public:
    int array[10] = {0};
    int flag[sizeof(array)]=  {false} ;

    void insert(int value) {
        int index = value%10;
        if (flag[index] == false) // not fill
        {
            array[index] = value; //index pr milgai
            flag[index] = true;
        }else {
            //agr nhi mili
            int i = 1;
            do {
               index =(value+(i*i)) % 10; //index agay krkay banaya

                if (flag[index]  == true) {
                    i++;
                }
                if (flag[index] == false )//not fill
                {
                    //daldo value
                    array[index] = value;
                    flag[index] = true;
                    return;
                }

            }while (i !=10);
            std::cout << "array totally filledd";
        }

    }
    void display() {
        for (int i = 0 ;i < 10 ; i++) {
          if (flag[i] == false) {
              cout<<"- ";
          }else {
              cout<<array[i]<<" ";
          }
        }
    }
    void search(int value) {
        int index= value%10;
        if (array[index] == value) {
            std::cout <<" index :"<<index;
            return;
        }
        int  i = 1;
        do {
            index =(int)(value+pow(i,2)) % 10;
            if (array[index] != value) {
                i++;
            }
            if (array[index] == value) {
                std::cout <<" index :"<<index;
                return;
            }
        }while (i!=10);
        std::cout<<"Not found :Sorry babeee";

    }
};


    int main() {
        QuadraticProbingWithInt* p = new QuadraticProbingWithInt();
        p->insert(33);
        p->insert(23);
        p->insert(43);
        p->insert(53);
        p->insert(63);
        p->insert(73);
        // p->insert(23);
        // p->insert(112);
        // p->insert(79);
        // p->insert(123);
        // p->insert(133);

        // p->display();
        // p->insert("ahmedullah");
        // p->search("ahmedullah");
        // p->insert(26);
        // p->insert(36);
        // p->insert(46);
        // p->insert(56);
        // p->insert(96);
        // p->insert(86);
        // p->insert(106);
        // p->insert(116);
        p->display();
        // p->search(16);


    }
