#include<iostream>
#include<conio.h>
#include<stack>
#include<cstdlib>


using namespace std;

template <class T>
struct node{
	T data;
	node* next;
};

template <class T>
class Stack{
	public:
        stack<T> auxillary;
		node<T>* top;
		Stack();
		bool isempty();
		void peek();
		void pop();
		void push(T);
		void display();
        T getMinimum();
};
template <class T>
Stack<T>::Stack(){
	top = NULL;
}
template <class T>
void Stack<T>::peek(){
	if(top==NULL){
		cout <<"\nStack is empty";
		return;
	}
	else{
		cout << "\nTop element: " << top->data;
	}
}
template <class T>
bool Stack<T>::isempty(){
	if(top == NULL){
		return true;
	}
    return false;
}

template <class T>
void Stack<T>::display(){
	node<T>* temp = top;
	if (temp == NULL){
		cout << "\nStack is empty...!";
		return;
	}
	while(temp != NULL ) {
		cout << temp->data <<",";
		temp = temp->next;
	}
}


template <class T>
void Stack<T>::pop(){
	node<T>* temp = top;
	if(temp==NULL){
		cout << "\nStack is empty..!";
		return;
	}
    auxillary.pop();
	top = temp->next;
	delete temp;
	return;
}
template <class T>
void Stack<T>::push(T element){
	node<T>* newnode = new node<T>;
	newnode->next = NULL;
	newnode->data = element;
	if(top == NULL){
		top = newnode;
        auxillary.push(element);
		return;
	}
	else{
        if(element < auxillary.top()){
            auxillary.push(element);
        }
        else {
            auxillary.push(auxillary.top());
        }
		newnode->next = top;
		top = newnode;
		return;
	}
}
template<class T>
T Stack<T>::getMinimum(){
    if (auxillary.empty()){
        cout << "Empty-";
        return 0;
    }
    return auxillary.top();
}
int main(){
	Stack<int> object;
	int choice;
	int element;
	while(1){
		cout <<"\n\n\n***********MENU*********\n1.PUSH \n2.POP \n3.peek element \n4.DISPLAY \n5.Get minimum of stack \n6.EXIT";
		cout << "\nEnter your choice: ";
	    cin >> choice;

	   switch(choice){
			case 1: cout << "Enter an element: ";
		            cin >> element;
				    object.push(element);
				    break;
		    case 2: object.pop();
				    break;
			case 3: object.peek();
			        break;
			case 4: cout <<"\nLinked list is: " ;
		            object.display();
		            break;
            case 5: cout << "Minimum element of the stack: "<<object.getMinimum();
                    break;
		    case 6: exit(0);
		    default: cout << "\nWrong choice...";
		}
	}
	getch();
	return 0;
}
