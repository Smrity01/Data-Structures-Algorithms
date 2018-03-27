/*
Split Circular linked list into two
Written by : Smrity Chaudhary
     Dated : 24-03-2018
*/
#include<iostream>
#include<conio.h>
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
		void front_deletion();
		void element_deletion(T);
		void display();
		void split(linkedlist<T>&);
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
	if(head == NULL){
		return true;
	}
	else{
		return false;
	}
}
template <class T>
void linkedlist<T>::insertion(T element){
	/*
	Objective       : Inserting in Linked list at the back
	Input parameter : Element to be inserted
	Output Values   : None
	Description     : Member function definition
	Approach        : Traverse the list till last element and insert the element at the back of linked list and pointers are adjusted 
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
void linkedlist<T>::element_deletion(T element){
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
void linkedlist<T>::split(linkedlist<T>& l2){
	/*
	Objective       : split the calling circular Linked list into two lists
	Input parameter : Linkedlist object as reference parameter
	Output Values   : None
	Description     : Member function definition
	Approach        : According to Floyd cycle detection two pointers are used slow and fast Till. 
	                  As  fast approaches to end the slow Approaches the middle of the list then split accordingly
	*/
	if(head == NULL){
		cout << "\nList is empty..";
		return;
	}
	if(head->next == head){
		cout << "\nOnly one element in the list";
		return;
	}
	node<T>* slow = head;
	node<T>* fast = head;
	while(fast->next != head && fast->next->next != head){
		slow = slow->next;
		fast = fast->next->next;
	}
	while(slow->next != head ){
		l2.insertion(slow->next->data);
		element_deletion(slow->next->data);
	}
	return;
}
int main(){
	/*
	Objective       : Main function of program
	Input parameter : None
	Output Values   : None
	Description     : Calling the required function of class
	Approach        : Take input form user and according to the choice the class function is called 
	*/
	linkedlist<int> object,l2;
	int choice;
	while(1){
		cout <<"\n\n\n***********MENU*********\n1.Insertion at Back  \n2.DISPLAY \n3.Split the list into two \n4.EXIT";
		cout << "\nEnter your choice: ";
	    cin >> choice;
	
	   switch(choice){
		    case 1: int element;
		            cout << "Enter an element: ";
		            cin >> element;
				    object.insertion(element);
				    object.display();
				    break;
			case 2: cout <<"\nLinked list is: " ;
		            object.display();
		            break;
		    case 3: cout <<"split the linkedlist into two..\n";
					object.split(l2);
		    		cout << "\n****previous list:****\n";
		    		object.display();
		    		cout << "\n****New list:***\n";
					l2.display();
					break;
		    case 4: exit(0);
		    default: cout << "\nWrong choice..."; 
		}
	}
	getch();
	return 0;
}
