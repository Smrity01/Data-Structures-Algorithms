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
void linkedlist<T>::end_deletion(){
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
