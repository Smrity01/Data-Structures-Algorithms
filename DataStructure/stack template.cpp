/*
Stack implementation using array
Written by : Smrity Chaudhary
     Dated : 07-02-2018
*/
#include<iostream>
#include<cstdlib>
//#define MAXSIZE 100
using namespace std;

template <class T>
class stack{
	/*
	Objective       : Creating a class stack to implement stack methods
	Input parameter : None
	Output Values   : None
	Description     : Class definition
	Approach        : Class defines data member and member function of the stack class
	*/
	public:
	    T *arr;
	    int top;
	    int capacity;
		stack();
		~stack();
		void push(T);
		T pop();
		T peek();
		int size();
		bool is_empty();
		bool is_full();
		void display();
};

template <class T>
stack<T>::stack(){
	/*
	Objective       : Constructor of a class stack
	Input parameter : None
	Output Values   : None
	Description     : Class Constructor
	Approach        : Initializing the variables of class stack 
	*/
	capacity = 0;
	arr = new T[capacity];
	top = -1;
}
template <class T>
stack<T>::~stack(){
	/*
	Objective       : Destructor of a class stack
	Input parameter : None
	Output Values   : None
	Description     : Class destructor
	Approach        : Deleting the variables of class stack
	*/
	delete[] arr;
}

template <class T>
bool stack<T>::is_empty(){
	/*
	Objective       : is_empty function of a class stack
	Input parameter : None
	Output Values   : None
	Description     : Class function
	Approach        : Just checking whether the stack is empty or not
	*/	
	if (top == -1){
		return true;
	}
	else{
		return false;
	}
}

template <class T>
bool stack<T>::is_full(){
	/*
	Objective       : Function of a class stack
	Input parameter : None
	Output Values   : None
	Description     : Class function
	Approach        : Just checking whether the stack is full or not
	*/
	if(top == capacity-1){
		return true;
	}
	else {
		return false;
	}
}

template <class T>
void stack<T>::push(T element){
	/*
	Objective       : Function of a class stack
	Input parameter : element that need to be inserted
	Output Values   : print if stack is full
	Description     : Class function
	Approach        : Inserting element in the stack
	*/
	if(is_full()){
		cout << "\nOOPS....Stack is full...\n";
	}
	else{
		top++;
		arr[top] = element;
	}
}

template <class T>
T stack<T>::pop(){
	/*
	Objective       : Function of a class stack
	Input parameter : None
	Output Values   : Print if stack is empty
	Description     : Class function
	Approach        : Moving out the top element from stack
	*/
	if(is_empty()){
		cout << "\nOOPS!...Stack is empty....\n";
		return 0;
	}
	else{
		int last = arr[top]; 
		top--;
		return last;
	}
}

template <class T>
T stack<T>::peek(){
	/*
	Objective       : Function of a class stack
	Input parameter : None
	Output Values   : Print if stack is empty
	Description     : Class function
	Approach        : Returning the top element from stack
	*/
	if(is_empty()){
	/*
	Objective       : Function of a class stack
	Input parameter : None
	Output Values   : Print if stack is empty
	Description     : Class function
	Approach        : Checking wether the stack is empty or not
	*/
		cout << "\nOOPS!...Stack is empty....\n";
		return 0;
	}
	else{ 
		return (arr[top]);
	}
}

template <class T>
int stack<T>::size(){
	/*
	Objective       : Function of a class stack
	Input parameter : None
	Output Values   : None
	Description     : Class function
	Approach        : Returning the value of top
	*/
	return(top+1);
}
template <class T>
void stack<T>::display(){
	/*
	Objective       : Function of a class stack
	Input parameter : None
	Output Values   : Print the elements of stack
	Description     : Class function
	Approach        : Traverse the array using for loop
	*/
	if(is_empty()){
		cout << "\nOOPS!...Stack is empty....\n";
	}
	else{
		for(int i = top;i>=0;i--){
			cout <<"\n|" <<arr[i] << "|";
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
	stack<float> object;
	cout << "Enter the size of the array: ";
	cin >> object.capacity;
	while(1){
		cout <<"\n\n\n***********MENU*********\n1.PUSH \n2.POP \n3.PEEK \n4.Size of STACK \n5.DISPLAY \n6.EXIT";
		cout << "\nEnter your choice: ";
	    cin >> choice;
	
	   switch(choice){
		    case 1: float element;
		            cout << "Enter an element: ";
		            cin >> element;
				    object.push(element);
				    break;
		    case 2: cout << "\nYou poped out this element: " << object.pop();
				    break;
		    case 3: cout << "\nPeek element of stack is: " << object.peek();
		            break;
		    case 4: cout <<"\nSize of Stack:  " << object.size();
		            break;
			case 5: cout <<"\nStack is: " ;
		            object.display();
		            break;
		    
		    case 6: exit(0);
		    default: cout << "\nWrong choice..."; 
		}
	}
	return 0;
}

