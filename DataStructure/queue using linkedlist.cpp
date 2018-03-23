#include<iostream>
#include<conio.h>
using namespace std;

template <class T>
struct node{
	T data;
	node* next;
};

template <class T>
class linkedlist{
	public:
		node<T>* head;
		linkedlist();
		void front();
		void insertion(T);
		bool isempty();
		void front_deletion();
		void display();
};
template <class T>
linkedlist<T>::linkedlist(){
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
void linkedlist<T>::front(){
	if(head==NULL){
		cout <<"\nQueue is empty";
		return;
	}
	else{
		cout << "\nTop element: " << head->data;
	}
}

template <class T>
void linkedlist<T>::insertion(T element){
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
void linkedlist<T>::front_deletion(){
	node<T>* temp = head;
	if(temp==NULL){
		cout << "\nLinked list is empty..!";
		return;
	}
	
	head = temp->next;
	delete temp;
	return;
}

int main(){
	linkedlist<int> object;
	int choice;
	while(1){
		cout <<"\n\n\n***********MENU*********\n1.Enqueue \n2.Dequeue \n3.front \n4.DISPLAY \n5.EXIT";
		cout << "\nEnter your choice: ";
	    cin >> choice;
	
	   switch(choice){
		    case 1: int element;
		            cout << "Enter an element: ";
		            cin >> element;
				    object.insertion(element);
				    break;
		    case 2: object.front_deletion();
				    break;
			case 3: object.front();
			        break;
			case 4: cout <<"\nLinked list is: " ;
		            object.display();
		            break;
		    case 5: exit(0);
		    default: cout << "\nWrong choice..."; 
		}
	}
	getch();
	return 0;
}
