/*
josephus Problem
Written by : Smrity Chaudhary
     Dated : 25-03-2018
*/
#include<iostream>
using namespace std;

template <class T>
struct node{
	/*
	Objective       : Creating a Structure of node of a linkedlist
	Input parameter : None
	Output Values   : None
	Description     : Node defines the node structure 
	Approach        : Struct defines data item is names element
	*/
    T data;
    node* next;
};

template <class T>
class linkedlist{
	/*
	Objective       : Creating a class Linkedlist 
	Input parameter : None
	Output Values   : None
	Description     : Class definition
	Approach        : Class defines data member and member function of the queue class
	*/
public:
    node<T>* head;
    linkedlist();
    void insertion(T);
    bool isempty();
    T length();
    void front_deletion();
    void deletion(T);
    void display();
    void elimination(int,int);
    
};
template <class T>
linkedlist<T>::linkedlist(){
	/*
	Objective       : Creating a constructor of class Linkedlist
	Input parameter : None
	Output Values   : None
	Description     : Constructor definition
	Approach        : Initialize the elements of class
	*/
    head = NULL;
}
template <class T>
bool linkedlist<T>::isempty(){
	/*
	Objective       : Check the list is empty or not
	Input parameter : None
	Output Values   : None
	Description     : Member function definition
	Approach        : Check whether head is null or not
	*/
    if(head == NULL){
        return true;
    }
    else{
        return false;
    }
}
template<class T>
T linkedlist<T>::length(){
	/*
	Objective       : To find the length of the list
	Input parameter : None
	Output Values   : None
	Description     : Member function definition
	Approach        : Traverse the list till last element and increment the counter as well
	*/
    int count = 0;
    node<T>* temp = head;
    if(temp == NULL){
        return 0;
    }
    else{
        count++;
        while(temp->next != head){
            temp = temp->next;
            count++;
        }
        return count;
    }
}
template <class T>
void linkedlist<T>::insertion(T element){
	/*
	Objective       : Inserting in Linked list at the back
	Input parameter : Element to be inserted
	Output Values   : None
	Description     : Member function definition
	Approach        : Traverse the list till last element and insert the element at the back of linked list
	*/
    node<T>* newnode = new node<T>;
    newnode->next = NULL;
    newnode->data = element;
    if(head == NULL){
        head = newnode;
        head->next = head;
        return;
    }
    node<T>* temp =head;
    while(temp->next != head){
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->next = head;
    
}
template <class T>
void linkedlist<T>::display(){
	/*
	Objective       : Displaying the elements of Linked list
	Input parameter : None
	Output Values   : Elements of linked list
	Description     : Member function definition
	Approach        : Traverse the list using while loop and print the elements as well
	*/
    node<T>* temp = head;
    if (temp == NULL){
        cout << "\nList is empty...!";
        return;
    }
    while(temp->next != head ) {
        cout << temp->data <<",";
        temp = temp->next;
    }
    cout << temp->data;
}
template <class T>
void linkedlist<T>::front_deletion(){
	/*
	Objective       : Delete the elements of Linked list from front
	Input parameter : None
	Output Values   : None
	Description     : Member function definition
	Approach        : Adjust the pointers first and then delete first element
	*/
    node<T>* temp = head;
    if(temp == NULL){
        cout << "\nLinked list is empty..!";
        return;
    }
    if(temp->next==head){
        head=NULL;
        delete temp;
        return;
    }
    while(temp->next != head){
        temp = temp->next;
    }
    node<T>* curr = head;
    head = curr->next;
    temp->next = head;
    delete curr;
    return;
}

template <class T>
void linkedlist<T>::deletion(T element){
	/*
	Objective       : Delete the given elements from circular Linked list
	Input parameter : Element that need to be deleted
	Output Values   : None
	Description     : Member function definition
	Approach        : First search for element then Adjust the pointers first and then delete the element
	*/
    node<T>* temp = head;
    if(temp==NULL){
        cout << "\nLinked list is empty..!";
        return;
    }
    if(temp->data == element){
        front_deletion();
        return;
    }
    while(temp->next!= head && temp->next->data != element ){
        temp = temp->next;
    }
    if (temp->next == head){
        cout << "Element not found...!";
        return;
    }
    node<T>* curr = temp->next;
    temp->next = curr->next;
    curr->next = NULL;
    delete curr;
    
}
template <class T>
void linkedlist<T>::elimination(int N,int M){
	/*
	Objective       : Eliminate every Mth person and find out the leader
	Input parameter : Number of persons and count of elimination
	Output Values   : None
	Description     : Member function definition
	Approach        : while loop used to travere the list and For loop within the while loop track the person which is to be eliminated
	                  delete the selected mth person and repeat the process until one element is left behind. 
	*/
    if(N == 1){
        cout << "\nOnly one person is sitting..";
        return;
    }
    node<T>* temp = head;
    node<T>* curr = temp->next;
    int rank = N;
    int count;
    while( head->next != head ){
        count = M;
        for(int count = 1;count<M-1;count++){
            temp = temp->next;
        }
        curr=temp->next;
        cout << "person:" << curr->data << " rank:" << rank << "\n";
        temp = curr->next;
        deletion(curr->data);
        rank--;
        
    }
    cout << "\nleader is: "<< head->data << " person with rank 1.\n";
    
}
int main(){
	/*
	Objective       : Main function of program
	Input parameter : None
	Output Values   : None
	Description     : Calling the required function of class
	Approach        : Take input form user and according to the choice the class function is called 
	*/
    linkedlist<int> object;
    int N;
    int M;
    cout << "Enter N:";
    cin >> N;
    cout << "\nEnter M:";
    cin >> M;
    for(int person=1;person<=N;person++){
        object.insertion(person);
    }
    object.elimination(N,M);
    return 0;
}
