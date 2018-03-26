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
		T length();
		void front_deletion();
		void deletion(T);
		void display();
		void elimination(int,int);
		
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
template<class T>
T linkedlist<T>::length(){
	int count = 0;
	node<T>* temp = head;
	if(temp == NULL){
		return 0;
	}
	else{
		count++;
		while(temp->next != head){
			temp = temp->next;
			count++;
		}
		return count;
	}
}
template <class T>
void linkedlist<T>::insertion(T element){
	node<T>* newnode = new node<T>;
	newnode->next = NULL;
	newnode->data = element;
	if(head == NULL){
		head = newnode;
		head->next = head;
		return;
	}
	node<T>* temp =head;
	while(temp->next != head){
		temp = temp->next;
	}
	temp->next = newnode;
	newnode->next = head;
	
}
template <class T>
void linkedlist<T>::display(){
	node<T>* temp = head;
	if (temp == NULL){
		cout << "\nList is empty...!";
		return;
	}
	while(temp->next != head ) {
		cout << temp->data <<",";
		temp = temp->next;
	}
	cout << temp->data;
}
template <class T>
void linkedlist<T>::front_deletion(){
	node<T>* temp = head;
	if(temp == NULL){
		cout << "\nLinked list is empty..!";
		return;
	}
	if(temp->next==head){
		head=NULL;
		delete temp;
		return;
	}
	while(temp->next != head){
		temp = temp->next;
	}
	node<T>* curr = head;
	head = curr->next;
	temp->next = head;
	delete curr;
	return;
}

template <class T>
void linkedlist<T>::deletion(T element){
	node<T>* temp = head;
	if(temp==NULL){
		cout << "\nLinked list is empty..!";
		return;
	}
	if(temp->data == element){
		front_deletion();
		return;
	}
	while(temp->next!= head && temp->next->data != element ){
		temp = temp->next;
	}
	if (temp->next == head){
		cout << "Element not found...!";
		return;
	}
	node<T>* curr = temp->next;
	temp->next = curr->next;
	curr->next = NULL;
	delete curr;
	
}
template <class T>
void linkedlist<T>::elimination(int N,int M){
	if(N == 1){
		cout << "\nOnly one person is sitting..";
		return;
	}
	node<T>* temp = head;
	int rank = N;
	int count;
	while( length()>1 ){
		count = M;
		for(int count = 1;count<M;count++){
			temp = temp->next;
		}
		cout << "person:" << temp->next->data << " rank:" << rank << "\n";
		deletion(temp->next->data);
		temp = temp->next;
		rank--;
	}
	cout << "\nleader is: "<< head->data << " person with rank 1.";

}
int main(){
	linkedlist<int> object;
	int N;
	int M;
	cout << "Enter N:";
	cin >> N;
	cout << "\nEnter M:";
	cin >> M;
	for(int person=1;person<=N;person++){
		object.insertion(person);
	}
	object.elimination(N,M);
	getch();
	return 0;
}
