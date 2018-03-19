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
		void element_deletion(T);
		void reverse_pair();
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
	while(temp->next != NULL ) {
		cout << temp->data <<",";
		temp = temp->next;
	}
	cout << temp->data;
}

template <class T>
void linkedlist<T>::reverse_pair(){
	node<T>* temp1 = head;
	node<T>* temp2 = head->next;
	node<T>* prev = NULL;
	while(temp2 != NULL){
		cout <<" temp1: " <<temp1->data;
		cout <<" temp2: " <<temp2->data;
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
int main(){
	linkedlist<int> object;
	object.insertion(1);
	object.insertion(15);
	object.insertion(16);
	object.display();
	object.reverse_pair();
	object.display();
	getch();
	return 0;
}
