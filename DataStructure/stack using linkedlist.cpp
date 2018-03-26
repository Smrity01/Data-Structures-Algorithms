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
		bool isempty();
		void top();
		void front_deletion();
		void front_insertion(T);
		void display();
};
template <class T>
linkedlist<T>::linkedlist(){
	head = NULL;
}
template <class T>
void linkedlist<T>::top(){
	if(head==NULL){
		cout <<"\nStack is empty";
		return;
	}
	else{
		cout << "\nTop element: " << head->data;
	}
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
template <class T>
void linkedlist<T>::front_insertion(T element){
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
	linkedlist<int> object;
	int choice;
	int element;
	while(1){
		cout <<"\n\n\n***********MENU*********\n1.PUSH \n2.POP \n3.TOP element \n4.DISPLAY \n5.EXIT";
		cout << "\nEnter your choice: ";
	    cin >> choice;
	
	   switch(choice){
			case 1: cout << "Enter an element: ";
		            cin >> element;
				    object.front_insertion(element);
				    break;
		    case 2: object.front_deletion();
				    break;
			case 3: object.top();
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
