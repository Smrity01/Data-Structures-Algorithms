/*
Stack implementation using Queue
Written by : Smrity Chaudhary
     Dated : 15-02-2018
*/
#include<iostream>
#include<queue>
using namespace std;

class Stack{
	/*
	Objective       : Creating a class stack to implement stack methods using queue
	Input parameter : None
	Output Values   : None
	Description     : Class definition
	Approach        : Class defines data member and member function of the stack class
	*/
	public:
		queue<int> q1;
		queue<int> q2;
		void stack_push(int);
		int stack_peek();
		void stack_pop();
		int stack_size();
		void display();
};
void Stack::stack_push(int element){
	/*
	Objective       : Function of a class stack
	Input parameter : Element that need to be inserted
	Output Values   : None
	Description     : Class function
	Approach        : Inserting element in the empty queue and then move all the from another queue to that queue
	*/
	if(q1.empty()){
		q1.push(element);
		while(!q2.empty()){
			q1.push(q2.front());
			q2.pop();
		}
	}
	else{
		q2.push(element);
		while(!q1.empty()){
			q2.push(q1.front());
			q1.pop();
	    }
		
	}
}
int Stack::stack_peek(){
	/*
	Objective       : Function of a class stack
	Input parameter : None
	Output Values   : None
	Description     : Class function
	Approach        : Returning the front element from queue
	*/
	if(q1.empty()){
		return q2.front();
	}
	else{
		return q1.front();
	}
}
void Stack::stack_pop(){
	/*
	Objective       : Function of a class stack
	Input parameter : None
	Output Values   : None
	Description     : Class function
	Approach        : Moving out the front element from queue
	*/
	if(q1.empty()){
		q2.pop();
		return;
	}
	else{
		q1.pop();
		return;
	}
}
int Stack::stack_size(){
	/*
	Objective       : Function of a class stack
	Input parameter : None
	Output Values   : None
	Description     : Class function
	Approach        : Returning the value of queue size
	*/
	if(q1.empty()){
		return q2.size();
	}
	else{
		return q1.size();
	}
}
void Stack::display(){
	/*
	Objective       : Function of a class stack
	Input parameter : None
	Output Values   : Print the elements of queue
	Description     : Class function
	Approach        : Traverse the queue using while loop(poping from one queue and inserting to another)
	*/
	if(q1.empty()){
		while(!q2.empty()){
			q1.push(q2.front());
			cout << q2.front() <<"|";
			q2.pop();
		}
	}
	else{
		while(!q1.empty()){
			q2.push(q1.front());
			cout << q1.front() <<"|";
			q1.pop();
	    }
		
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
	int choice;
	Stack object;
	while(1){
		cout <<"\n\n\n***********MENU*********\n1.PUSH \n2.POP \n3.PEEK \n4.DISPLAY \n5.EXIT";
		cout << "\nEnter your choice: ";
	    cin >> choice;
	
	   switch(choice){
		    case 1: int element;
		            cout << "Enter an element: ";
		            cin >> element;
				    object.stack_push(element);
				    break;
		    case 2: cout << "\nYou poped out top element: " ;
		    		object.stack_pop();
				    break;
		    case 3: cout << "\nPeek element of stack is: " << object.stack_peek();
		            break;
		    case 4: cout <<"\nStack is: " ;
		            object.display();
		            break;
		    case 5: exit(0);
		    default: cout << "\nWrong choice..."; 
		}
	}
	return 0;	
}

