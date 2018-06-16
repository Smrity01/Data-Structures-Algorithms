/*
Length and middle element of linked list
Written by : Smrity Chaudhary
    Dated  : 15/06/2018
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
	Approach        : Class defines data member and member function of the queue
                    class
	*/
	public:
		node<T>* head;
		linkedlist();
		void insertion(T);
		bool isempty();
		int length_iterative();
		int length_recursive(node<T>*temp);
		void middle();
		void middle_pointers();
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
int linkedlist<T>::length_iterative(){
	  /*
		Objective       : Length of The Linked list
		Input parameter : None
		Output Values   : None
		Description     : Member function definition
		Approach        : Iteratively traverse the linked list and count the elements.
		*/
		if(head == NULL){
			return 0;
		}
		node<T>* temp = head;
		int length = 0;
		while(temp != NULL){
			temp = temp->next;
			length++;
		}
		return length;
}
template <class T>
int linkedlist<T>::length_recursive(node<T>*temp){
	/*
	Objective       : Length of The Linked list
	Input parameter : Head of the linked list
	Output Values   : None
	Description     : Member function definition
	Approach        : Recursively traverse the linked list and count the elements.
	*/
	if(temp == NULL){
		return 0;
	}
	int length = 1;
	length = length + length_recursive(temp->next);
	return length;
}
template <class T>
void linkedlist<T>::middle(){
	/*
	Objective       : Middle element of The Linked list
	Input parameter : None
	Output Values   : None
	Description     : Member function definition
	Approach        : Iteratively traverse the linked list and find Middle
	                  the element.
	*/
	if(head == NULL){
		cout << "No element ";
		return;
	}

	if(head->next == NULL){
		cout << "Middle element: " << head->data;
		return;
	}
	int count = length_iterative();
	node<T>* temp = head;
	int travel = 1;
	while(count > 2 && travel < count/2){
		temp = temp->next;
		travel++;
	}
	if(count%2 == 0){
	cout << "Middle elements: " << temp->data << "," << temp->next->data;
}
else{
	cout << "Middle element: " << temp->next->data;
}
return;
}
template <class T>
void linkedlist<T>::middle_pointers(){
	/*
	Objective       : Middle element of The Linked list
	Input parameter : None
	Output Values   : None
	Description     : Member function definition
	Approach        : Using two pointers fast and slow
	*/
	if(head == NULL){
		cout << "\nlist is empty...";
		return;
	}
	node<T>*fast = head;
	node<T>*slow = head;
	while(fast!=NULL && fast->next != NULL){
		slow = slow->next;
		fast = fast->next->next;
	}
	cout << "Middle is: " << slow->data;
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
	linkedlist<int> object;
	int choice;
	while(1){
		cout <<"\n\n\n***********MENU*********\n1.Insertion"
         << "\n2.length of the linked list \n3.DISPLAY \n4.Middle element"
				 << "\n5.Recursive length \n6.Middle element with different Approach \n7.EXIT";
		cout << "\nEnter your choice: ";
	   cin >> choice;

	   switch(choice){
		    case 1: int element;
		            cout << "Enter an element: ";
		            cin >> element;
				        object.insertion(element);
				    break;
		    case 2:
				    cout << "Length of the linked list is: " <<object.length_iterative();
				    break;
		    case 3: cout <<"\nLinked list is: " ;
                object.display();
  		       break;
		    case 4: object.middle();
				     break;
				case 5: cout << "length is: " << object.length_recursive(object.head);
				     break;
				case 6: object.middle_pointers();
				     break;
				case 7:exit(0);
		    default: cout << "\nWrong choice...";
		}
	}
	getch();
	return 0;
}
