/*
Implementation of linked list(using node Structure) - insertions adn deletions
Written by : Smrity Chaudhary
    Dated  : 21/03/2018
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
		void end_deletion();
		void front_deletion();
		void element_deletion(T);
		void front_insertion(T);
		void display();
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
	Objective       : check whether the Linked list is empty or not
	Input parameter : None
	Output Values   : None
	Description     : Member function definition
	Approach        : Simple if conditons to check if head pointer is null then linked list is null
	*/
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
	Approach        : Traverse the list till last element and insert the element at the back of linked list
	*/
	node<T>* newnode = new node<T>;
	newnode->next = NULL;
	newnode->data = element;
	if(head == NULL){
		head = newnode;
		return;
	}
	node<T>* temp =head;
	while(temp->next != NULL){
		temp = temp->next;
	}
	temp->next = newnode;
	
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
	while(temp != NULL ) {
		cout << temp->data <<",";
		temp = temp->next;
	}
}

template <class T>
void linkedlist<T>::end_deletion(){
	/*
	Objective       : Delete element of Linked list from end
	Input parameter : None
	Output Values   : None
	Description     : Member function definition
	Approach        : Traverse the list using while loop until last second element and delete last  element
	*/
	node<T>* temp = head;
	if(temp==NULL){
		cout << "\nLinked list is empty..!";
		return;
	}
	if(temp->next==NULL){
		head=NULL;
		delete temp;
		return;
	}
	while(temp->next->next != NULL){
		temp=temp->next;	
	}
	node<T>* curr = temp->next;
	temp->next = NULL;
	delete curr;
	return;
}

template <class T>
void linkedlist<T>::front_deletion(){
	/*
	Objective       : Delete element of Linked list from front
	Input parameter : None
	Output Values   : None
	Description     : Member function definition
	Approach        : Delete first element from list and adjust head pointer accordingly
	*/
	node<T>* temp = head;
	if(temp==NULL){
		cout << "\nLinked list is empty..!";
		return;
	}
	
	head = temp->next;
	delete temp;
	return;
}
template <class T>
void linkedlist<T>::element_deletion(T element){
	/*
	Objective       : Delete given element from Linked list 
	Input parameter : Element that need to be deleted
	Output Values   : None
	Description     : Member function definition
	Approach        : Traverse the list using while loop until to find given element, 
	                  delete that element and adjust the pointer accordingly
	*/
	node<T>* temp = head;
	if(temp==NULL){
		cout << "\nLinked list is empty..!";
		return;
	}
	if(temp->data == element){
		head = temp->next;
		delete temp;
		return;
	}
	while(temp->next->data != element ){
		temp=temp->next;	
	}
	if (temp==NULL){
		cout << "Element not found...!";
		return;
	}
	node<T>* curr = temp->next;
	temp->next = curr->next;
	curr->next = NULL;
	delete curr;
	
}
template <class T>
void linkedlist<T>::front_insertion(T element){
	/*
	Objective       : Inserting in Linked list at front
	Input parameter : Element to be inserted
	Output Values   : None
	Description     : Member function definition
	Approach        : Insert element at front and adjust head pointer of linked list
	*/
	node<T>* newnode = new node<T>;
	newnode->next = NULL;
	newnode->data = element;
	if(head == NULL){
		head = newnode;
		return;
	}
	else{
		newnode->next = head;
		head = newnode;
		return;
	}
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
	int choice;
	while(1){
		cout <<"\n\n\n***********MENU*********\n1.Insertion at Back \n2.Insertion At front \n3.Delete Front \n4.Delete Back \n5.Delete element \n6.DISPLAY \n7.EXIT";
		cout << "\nEnter your choice: ";
	    cin >> choice;
	
	   switch(choice){
		    case 1: int element;
		            cout << "Enter an element: ";
		            cin >> element;
				    object.insertion(element);
				    break;
			case 2: cout << "Enter an element: ";
		            cin >> element;
				    object.front_insertion(element);
				    break;
		    case 3: object.front_deletion();
				    break;
		    case 4: object.end_deletion();
		            break;
		            
		    case 5: cout << "Enter an element: ";
		            cin >> element;
				    object.element_deletion(element);
		            break;
			case 6: cout <<"\nLinked list is: " ;
		            object.display();
		            break;
		    case 7: exit(0);
		    default: cout << "\nWrong choice..."; 
		}
	}
	getch();
	return 0;
}
