#include<iostream>
#include<conio.h>
using namespace std;

struct node{
	int data;
	node* next;
};

class linkedlist{
	public:
		node* head;
		linkedlist();
		void insertion(int);
		void end_deletion();
		void front_deletion();
		void element_deletion(int);
		void front_insertion(int);
		void display();
};

linkedlist::linkedlist(){
	head = NULL;
}
void linkedlist::insertion(int element){
	node* newnode = new node;
	newnode->next = NULL;
	newnode->data = element;
	if(head == NULL){
		head = newnode;
		return;
	}
	node* temp =head;
	while(temp->next != NULL){
		temp = temp->next;
	}
	temp->next = newnode;
	
}
void linkedlist::display(){
	node* temp = head;
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

void linkedlist::end_deletion(){
	node* temp = head;
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
	node* curr = temp->next;
	temp->next = NULL;
	delete curr;
	return;
}

void linkedlist::front_deletion(){
	node* temp = head;
	if(temp==NULL){
		cout << "\nLinked list is empty..!";
		return;
	}
	head = temp->next;
	delete temp;
	return;
}
void linkedlist::element_deletion(int element){
	node* temp = head;
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
	node* curr = temp->next;
	temp->next = curr->next;
	curr->next = NULL;
	delete curr;
	
}
void linkedlist::front_insertion(int element){
	node* newnode = new node;
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
	/*
	Objective       : Main function of program
	Input parameter : None
	Output Values   : None
	Description     : Calling the required function of class
	Approach        : Take input form user and according to the choice the class function is called 
	*/
	linkedlist object;
	int choice;
	while(1){
		cout <<"\n\n\n***********MENU*********\n1.Insertion at Back \n2.Insertion at front \n3.Delete Front \n4.Delete Back \n5.Delete element \n6.DISPLAY \n7.EXIT";
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
