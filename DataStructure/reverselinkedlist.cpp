/*
Reverse of the linked list
Written by : Smrity Chaudhary
    Dated  : 22/01/2019
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
class Linkedlist{
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
		Linkedlist();
		void insertBack(T);
		bool isEmpty();
		int lengthOfList();
		void reverseList();
		void displayList();
};
template <class T>
Linkedlist<T>::Linkedlist(){
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
bool Linkedlist<T>::isEmpty(){
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
void Linkedlist<T>::insertBack(T element){
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
void Linkedlist<T>::displayList(){
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
int Linkedlist<T>::lengthOfList(){
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
void Linkedlist<T>::reverseList() {
    if (head == NULL) {
        cout << "\nList is empty...";
    }
    else if(head->next == NULL) {
        cout << "\nOnly one element in the list...";
    }
    else {
        node<T>* curr = head;
        node<T>* temp = curr->next;
        node<T>* prev = NULL;
        while (temp != NULL) {
            curr->next = prev;
            prev = curr;
            curr = temp;
            temp = temp->next;
        }
        curr->next = prev;
        head = curr;
    }
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
	Linkedlist<int> object;
	int choice;
	while(1){
		cout <<"\n\n\n***********MENU*********\n1.Insertion"
         << "\n2.length of the linked list \n3.DISPLAY \n4."
				 << "Reverse The list  \n5.EXIT";
		cout << "\nEnter your choice: ";
	   cin >> choice;

	   switch(choice){
		    case 1: int element;
		            cout << "Enter an element: ";
		            cin >> element;
				        object.insertBack(element);
				    break;
		    case 2:
				    cout << "Length of the linked list is: " <<object.lengthOfList();
				    break;
		    case 3: cout <<"\nLinked list is: " ;
                object.displayList();
  		       break;
		    case 4: cout << "Reverse List: \n";
				    object.reverseList();
				    if(!object.isEmpty()){
                      object.displayList();
				    }
				     break;
				//case 5: exit(0);
		    default: cout << "\nWrong choice...";
		}
	}
	getch();
	return 0;
}
