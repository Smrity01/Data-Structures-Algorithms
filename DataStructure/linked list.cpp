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
		void end_deletion();
		void front_deletion();
		void element_deletion(T);
		//void front_insertion(T);
		void display();
};
template <class T>
linkedlist<T>::linkedlist(){
	head = NULL;
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
	cout << "\n LL\n";
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
//template <class T>
//void linkedlist<T>::
int main(){
	linkedlist<int> object;
	object.insertion(1);
	object.insertion(15);
	object.insertion(16);
	object.insertion(31);
	object.display();
	object.element_deletion(31);
	object.display();
	getch();
	return 0;
}
