#include<iostream>
#include<string>
#include<list>

using namespace std;


/*
start
1. create strucutre Node of data and next ptr of typr Node itslef
2. create pointer of type node head and tail both pointing to nullptr.
3. for taking numbers of input use for loop.
4. initiating local integer take input as values.
5. create a newNode pointer of type Node pointing to object of Node.
6. assign neewnode-> data the value and assign newnode->neext to nullptr.
7. for the first node value input if fhead is equal to nullptr assign head = tail = newnode.
8. or else tail is equal to tail->next = newnode  and tail is equal newnode.
9. to print linked list, create a pointer of node type as current = head.
10. print till current is not poitoijg to nullptr; print current->data and assign current->next.
11. free memory by creating pointer of type node which is equal to current(head).
12. assign current-next to current and delete temp.

*/

struct Node{
    int data;
    Node* next;

};

int main(){
    list<string>cars = {"BMW", "3", "Mercedes", "Toyota"};
    cars.push_back("Ford");
    cars.push_front("Chevrolet");
    cars.insert(cars.begin(), "Jeep");
    for(string i : cars){
        cout<<i<<endl;
    }

    cout<<cars.front()<<endl; //Jeep
    cout<<cars.back()<<endl; //Ford

    cars.pop_back();
    cars.pop_front();

    for(string i : cars){
        cout<<i<<endl;
    }
    //-------------------------------------------------------------------------------------------------

    Node* head = nullptr;
    Node* tail = nullptr;

    for (int i = 0; i<5; i++){
        int value;
        cin>>value;

        // creating linked list , CREATE NEW NODE

        Node* newNode = new Node; 
        newNode->data = value;
        newNode->next = nullptr;

        if(head == nullptr){
            head = tail = newNode; // first node
        }
        else{
                tail->next = newNode;
                tail = newNode;
        }

    }
    

    //display the linked list
    cout<<"linked List : " <<endl;
    Node* current = head;
    while(current != nullptr){
        cout<<current->data << " "<<endl;
        current = current->next;
    }

    //free

    while(current != nullptr){
        Node* temp = current;
        current = current->next;
        delete temp;
    }



    return 0;
}