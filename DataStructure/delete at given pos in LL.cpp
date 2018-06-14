/*
Deleting an element at given position in linked list
Written by : Smrity Chaudhary
    Dated  : 14/06/2018
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
		void pos_deletion(int pos);
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
		cout << "\nList is empty...!";
		return;
	}
	while(temp != NULL ) {
		cout << temp->data <<",";
		temp = temp->next;
	}
}

template <class T>
void linkedlist<T>::pos_deletion(int pos){
	/*
	Objective       : Delete element of Linked list from given position
	Input parameter : Positon of element to be deleted
	Output Values   : None
	Description     : Member function definition
	Approach        : Traverse the list using while loop until it reaches given
                    position and delete that element
	*/
	node<T>* temp = head;
	if(temp==NULL){
		cout << "\nLinked list is empty..!";
		return;
	}
  if(pos == 1){
    head = head->next;
    delete temp;
    return;
  }
	int counter = 1;
  node<T>* prev = temp;
  while(temp != NULL && counter != pos){
    prev = temp;
    temp = temp->next;
    counter++;
  }
  if(temp==NULL){
		cout << "\nNo such position in linkedlist!";
		return;
	}
  prev->next = temp->next;
  delete temp;
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
         << "\n2.Deletion at given position \n3.DISPLAY \n4.EXIT";
		cout << "\nEnter your choice: ";
	    cin >> choice;

	   switch(choice){
		    case 1: int element;
		            cout << "Enter an element: ";
		            cin >> element;
				        object.insertion(element);
				    break;
		    case 2: int pos;
                cout << "enter a position of element you want to delete"
                    << "(position starts with 1) ";
                cin >> pos;
                object.pos_deletion(pos);
				    break;
		    case 3: cout <<"\nLinked list is: " ;
                object.display();
  		       break;
		    case 4: exit(0);
		    default: cout << "\nWrong choice...";
		}
	}
	getch();
	return 0;
}
