/*
Queue implementation using array
Written by : Smrity Chaudhary
     Dated : 14-03-2018
*/
#include<iostream>
#include<cstdlib>
using namespace std;

template <class T>
class queue{
		/*
	Objective       : Creating a class Queue to implement queue methods
	Input parameter : None
	Output Values   : None
	Description     : Class definition
	Approach        : Class defines data member and member function of the queue class
	*/
	public:
		T *arr;
		int front;
		int rear;
		int capacity;
		int count;
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
	/*
	Objective       : Creating a class Queue constructor
	Input parameter : None
	Output Values   : None
	Description     : Class Constructor definition
	Approach        : Initializing the variables of class Queue
	*/
	capacity = 0;
	arr = new T[capacity];
	front = -1;
	rear = -1;
	count = 0;
}
template <class T>
queue<T>::~queue(){
	/*
	Objective       : Destructor of a class Queue
	Input parameter : None
	Output Values   : None
	Description     : Class destructor
	Approach        : Deleting the variables of class Queue
	*/
	delete[] arr;
}

template <class T>
bool queue<T>::isempty(){
	/*
	Objective       : is_empty function of a class queue
	Input parameter : None
	Output Values   : None
	Description     : Class function
	Approach        : Just checking whether the queue is empty or not
	*/
	if(front == -1 && rear == -1){
	   return true;
	}
	else {
	   return false;
	}
}

template <class T>
bool queue<T>::isfull(){
	/*
	Objective       : Function of a class Queue
	Input parameter : None
	Output Values   : None
	Description     : Class function
	Approach        : Just checking whether the Queue is full or not
	*/
	if(rear == capacity-1 && front == (rear+1)%capacity){
		return true;
	}
	else{
		return false;
	}
}

template <class T>
void queue<T>::enqueue(T element){
	/*
	Objective       : Function of a class Queue
	Input parameter : Element that need to be inserted
	Output Values   : print if queue is full
	Description     : Class function
	Approach        : Inserting element in the queue at back(rear)
	*/
	if(isfull()){
		cout << "Queue is full...!\n";
	}
	else{
		if (isempty()){
			front ++;
		}
		rear++;
		arr[rear] = element;
		count++;
	}
}

template <class T>
void queue<T>::dequeue(){
	/*
	Objective       : Function of a class queue
	Input parameter : None
	Output Values   : Print if queue is empty
	Description     : Class function
	Approach        : Moving out the front element from queue
	*/
	if(isempty()){
		cout << "Queue is empty..!\n";
	}
	else{
		front++;
		count--;
	}
}

template <class T>
T queue<T>::peek(){
	/*
	Objective       : Function of a class queue
	Input parameter : None
	Output Values   : Print if queue is empty
	Description     : Class function
	Approach        : Returning the front element from queue
	*/
	if(isempty()){
		cout << "Queue is empty..!\n";
	}
	else{
		return arr[front];
	}
}

template <class T>
int queue<T>::size(){
	/*
	Objective       : Function of a class queue
	Input parameter : None
	Output Values   : None
	Description     : Class function
	Approach        : Returning the difference between rear and front (size of queue)
	*/
	return count;
}

template <class T>
void queue<T>::display(){
	/*
	Objective       : Function of a class queue
	Input parameter : None
	Output Values   : Print the elements of queue
	Description     : Class function
	Approach        : Traverse the array using for loop
	*/
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

