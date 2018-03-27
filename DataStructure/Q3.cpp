/*
Reverse in Pair of linked list
Written by : Smrity Chaudhary
     Dated : 20-03-2018
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
		void element_deletion(T);
		void reverse_pair();
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
	cout << "\n LL\n";
	while(temp->next != NULL ) {
		cout << temp->data <<",";
		temp = temp->next;
	}
	cout << temp->data;
}

template <class T>
void linkedlist<T>::reverse_pair(){
	/*
	Objective       : Reverse in Linked list in pair
	Input parameter : None
	Output Values   : None
	Description     : Member function definition
	Approach        : Traverse and reversing elements pair by pair
	*/
	node<T>* temp1 = head;
	node<T>* temp2 = head->next;
	node<T>* prev = NULL;
	while(temp2 != NULL){
		temp1->next = temp2->next;
		temp2->next = temp1;
		if(prev != NULL){
			prev->next = temp2;
		}
		if(head == temp1){
			head = temp2;
		}
		prev = temp1;
		if((temp1->next == NULL)||(temp1 == NULL)){
			break;
		}
		else{
			temp1 = temp1->next;
			temp2 = temp1->next;
		}	
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
		cout <<"\n\n\n***********MENU*********\n1.Insertion at Back \n2.Reverse in pair \n3.EXIT";
		cout << "\nEnter your choice: ";
	    cin >> choice;
	
	   switch(choice){
		    case 1: int element;
		            cout << "Enter an element: ";
		            cin >> element;
				    object.insertion(element);
				    object.display();
				    break;
			case 2: object.reverse_pair();
					object.display();
				    break;

		    case 3: exit(0);
		    default: cout << "\nWrong choice..."; 
		}
	}
	getch();
	return 0;
}
