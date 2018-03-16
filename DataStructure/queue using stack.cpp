/*
Queue implementation using stack
Written by : Smrity Chaudhary
     Dated : 15-03-2018
*/
#include<iostream>
#include<stack>
using namespace std;

class Queue{
	/*
	Objective       : Creating a class Queue to implement queue methods using stack
	Input parameter : None
	Output Values   : None
	Description     : Class definition
	Approach        : Class defines data member and member function of the queue class
	*/
	public:
		stack<int> s1,s2;
		void queue_push(int);
		int queue_peek();
		void queue_pop();
		int queue_size();
		void display();
};
void Queue::queue_push(int element){
	/*
	Objective       : Function of a class Queue
	Input parameter : Element that need to be inserted
	Output Values   : None
	Description     : Class function
	Approach        : Inserting element in the stack(poping from one and inserting in second stack)
	*/
	if(s1.empty()){
		while(!s2.empty()){
			s1.push(s2.top());
			s2.pop();
		}
		s2.push(element);
		while(!s1.empty()){
			s2.push(s1.top());
			s1.pop();
		}
	}
	else{
		while(!s1.empty()){
			s2.push(s1.top());
			s1.pop();
		}
		s1.push(element);
		while(!s2.empty()){
			s1.push(s2.top());
			s2
			.pop();
		}
	}
}
int Queue::queue_peek(){
	/*
	Objective       : Function of a class queue
	Input parameter : None
	Output Values   : None
	Description     : Class function
	Approach        : Returning the Top element from stack
	*/
	if(s1.empty()){
		return s2.top();
	}
	else{
		return s1.top();
	}
}
void Queue::queue_pop(){
	/*
	Objective       : Function of a class queue
	Input parameter : None
	Output Values   : Print if queue is empty
	Description     : Class function
	Approach        : Moving out the top element from queue
	*/
	if(s1.empty()){
		s2.pop();
	}
	else{
		s1.pop();
	}
}
int Queue::queue_size(){
	/*
	Objective       : Function of a class queue
	Input parameter : None
	Output Values   : None
	Description     : Class function
	Approach        : Returning the size of filled stack
	*/
	if(s1.empty()){
		return s2.size();
	}
	else{
		return s1.size();
    }
}
void Queue::display(){
	/*
	Objective       : Function of a class queue
	Input parameter : None
	Output Values   : Print the elements of queue
	Description     : Class function
	Approach        : Traverse the stack using while loop(poping from one and inserting in second stack)
	*/
	if(s1.empty()){
		s1 = s2;
		while(!s1.empty()){
			cout << s1.top() <<"|";
			s1.pop();
		}
	}
	else{
		s2 = s1;
		while(!s2.empty()){
			cout << s2.top() <<"|";
			s2.pop();
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
	Queue object;
	while(1){
		cout <<"\n\n\n***********MENU*********\n1.PUSH \n2.POP \n3.PEEK \n4.DISPLAY \n5.Size \n6.EXIT";
		cout << "\nEnter your choice: ";
	    cin >> choice;
	
	   switch(choice){
		    case 1: int element;
		            cout << "Enter an element: ";
		            cin >> element;
				    object.queue_push(element);
				    break;
		    case 2: cout << "\nYou poped out top element: " ;
		    		object.queue_pop();
				    break;
		    case 3: cout << "\nPeek element of queue is: " << object.queue_peek();
		            break;
		    case 4: cout <<"\nQueue is: " ;
		            object.display();
		            break;
		    case 5: cout <<"\nSize of Queue is: " ;
		            object.queue_size();
		            break;
		    case 6: exit(0);
		    default: cout << "\nWrong choice..."; 
		}
	}
	return 0;	
}
