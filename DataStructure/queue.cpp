/*
Queue implementation using array
Written by : Smrity Chaudhary
     Dated : 12-03-2018
*/
#include<iostream>
#include<cstdlib>
using namespace std;

template <class T>
class queue{
		/*
	Objective       : Creating a class stack to implement stack methods
	Input parameter : None
	Output Values   : None
	Description     : Class definition
	Approach        : Class defines data member and member function of the stack class
	*/
	public:
		T *arr;
		int front;
		int rear;
		int capacity;
		queue();
		~queue();
		void enqueue(T);
		void dequeue();
		T peek();
		bool isempty();
		bool isfull();
		void display();
		int size();
};

template <class T>
queue<T>::queue(){
	capacity = 0;
	arr = new T[capacity];
	front = -1;
	rear = -1;
}
template <class T>
queue<T>::~queue(){
	delete[] arr;
}

template <class T>
bool queue<T>::isempty(){
	if(front == -1 && rear == -1){
	   return true;
	}
	else {
	   return false;
	}
}

template <class T>
bool queue<T>::isfull(){
	if(rear == capacity-1){
		return true;
	}
	else{
		return false;
	}
}

template <class T>
void queue<T>::enqueue(T element){
	if(isfull()){
		cout << "Queue is full...!\n";
	}
	else{
		if (isempty()){
			front ++;
		}
		rear++;
		arr[rear] = element;
	}
}

template <class T>
void queue<T>::dequeue(){
	if(isempty()){
		cout << "Queue is empty..!\n";
	}
	else{
		front++;
	}
}

template <class T>
T queue<T>::peek(){
	if(isempty()){
		cout << "Queue is empty..!\n";
	}
	else{
		return arr[front];
	}
}

template <class T>
int queue<T>::size(){
	return rear-front+1;
}

template <class T>
void queue<T>::display(){
	if(isempty()){
		cout << "Queue is empty....\n";
	}
	else{
		for(int i = front;i<=rear;i++){
			cout <<"|" <<arr[i] << "|";
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
	queue<int> object;
	cout << "Enter the size of the array: ) ";
	cin >> object.capacity;
	while(object.capacity <= 0 ){
		cout <<"Size should be greater than 0...!";
		cout << "Enter the size of the array: ";
		cin >> object.capacity;	
	}
	while(1){
		cout <<"\n\n\n***********MENU*********\n1.ENQUEUE \n2.DEQUEUE \n3.PEEK \n4.Size of STACK \n5.DISPLAY \n6.EXIT";
		cout << "\nEnter your choice: ";
	    cin >> choice;
	
	   switch(choice){
		    case 1: int element;
		            cout << "Enter an element: ";
		            cin >> element;
				    object.enqueue(element);
				    break;
		    case 2: cout << "\nYou poped out the front element: ";
		    		object.dequeue();
				    break;
		    case 3: cout << "\nPeek element of Queue is: " << object.peek();
		            break;
		    case 4: cout <<"\nSize of Queue:  " << object.size();
		            break;
			case 5: cout <<"\nQueue is: " ;
		            object.display();
		            break;
		    
		    case 6: exit(0);
		    default: cout << "\nWrong choice..."; 
		}
	}
	return 0;
}

