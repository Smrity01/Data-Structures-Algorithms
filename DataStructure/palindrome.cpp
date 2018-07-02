/*
check Palindrome in linked list
Written by : Smrity Chaudhary
    Dated  : 02/07/2018
*/
#include<iostream>
#include<conio.h>
#include<cstring>
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
	Approach        : Class defines data member and member function of the queue
                    class
	*/
	public:
		node<T>* head;
		linkedlist();
		void insertion(T);
		bool isempty();
		void palindrome(node<T>* head);
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
	Approach        : Simple if conditons to check if head pointer is null then
                    linked list is null
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
	Approach        : Traverse the list till last element and insert the element
                   at the back of linked list
	*/
	node<T>* newnode = new node<T>;
	newnode->next = NULL;
	newnode->data = element;
	if(head == NULL){
		head = newnode;
		return;
	}
	node<T>* temp = head;
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
	Approach        : Traverse the list using while loop and print the elements as
                    well
	*/
	node<T>* temp = head;
	if (temp == NULL){
		cout << " empty...";
		return;
	}
	while(temp != NULL ) {
		cout << temp->data <<",";
		temp = temp->next;
	}
}

template <class T>
void linkedlist<T>::palindrome(node<T>* head){
	/*
	Objective       : Check Palindrome in the Linked list
	Input parameter : Head of the list
	Output Values   : None
	Description     : Member function definition
	Approach        : Using 3 pointers-
	                  -'cur' pointer to Traverse (Or to move end pointer)
										COMPARING POINTERS
										-'tail' pointer to compare letter from end of string
										-'head' pointer to compare Letter from start of string
	*/
	if(head == NULL){
		cout << "\nlist is empty...";
		return;
	}
	// point tail pointer at the end
	node<T>* tail = head;
	while(tail->next != NULL){
		tail = tail->next;
	}
	//  to terminate if first letter doesn't match with last
	if(head->next == NULL || tail->data != head->data){
		cout << "String not a palindrome";
		return;
	}
	// to check further letters of the string
	node<T>* cur = NULL;
	while(tail->next == head && head != cur){
		cur = head;
		while(cur->next != tail){
			cur = cur->next;
		}
		if(tail->data != head->data){
			cout << "String is not a palindrome";
			return;
		}
		tail = cur;
		head = head->next;
	}
	cout << "String is a palindrome";
	return;
}

int main(){
	/*
	Objective       : Main function of program
	Input parameter : None
	Output Values   : None
	Description     : Calling the required function of class
	Approach        : Take input form user and according to the choice the class
                   function is called
	*/
	linkedlist<string> object;
	int choice;
	string element;
	while(1){
		cout <<"\n\n\n***********MENU*********\n1.Insertion"
         << "\n2.Palindrome \n3.EXIT";
		cout << "\nEnter your choice: ";
	   cin >> choice;
	   switch(choice){
		    case 1: cout << "Enter the alphabet: ";
		            cin >> element;
				        object.insertion(element);
				    break;
		    case 2: object.palindrome(object.head);
				    break;
		    case 3: exit(0);
		    default: cout << "\nWrong choice...";
		}
	}
	getch();
	return 0;
}
