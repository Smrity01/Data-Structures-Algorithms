/*
Reverse in Pair of linked list
Written by : Smrity Chaudhary
     Dated : 20-03-2018
*/
#include<iostream>
#include<conio.h>
#include<math.h>
#include<stack>
#include<queue>
using namespace std;

bool check_consecutive(int,int);
void all_consecutive(stack<int>);
int main(){
	/*
	Objective       : Main function of program
	Input parameter : None
	Output Values   : None
	Description     : Calling the required function of class
	Approach        : Take input form user and according to the choice the class function is called 
	*/
  stack <int> s;
  int count;
  cout <<" How many elements do you want to enter: ";
  cin >> count;
  int element;
  for (int i=0;i<count;i++) {
    cout << "\nEnter element: ";
    cin >> element;
    s.push(element);
  }
  all_consecutive(s);
  getch();
  return 0;
}

bool check_consecutive(int num1,int num2){
	/*
	Objective       : To check for consecutive pairs
	Input parameter : Two numbers which need to be check
	Output Values   : None
	Description     : Boolean function definition
	Approach        : Compare both the numbers
	*/
	if(fabs(num1-num2)==1){
		return true;
	}
	else{
	 return false;
	 }
}

void all_consecutive(stack<int> s){
	/*
	Objective       : To check for All consecutive pairs in stack
	Input parameter : Object of stack
	Output Values   : None
	Description     : Void function definition
	Approach        : By pushing top element of stack into Queue and compairing it with immediate top of the stack
	*/    
	queue <int> q;
	int size_stack = s.size();
	if(s.empty()){
		cout<<"\nstack is empty...";
		return;
	}
	if(size_stack%2 == 1)
	{
		s.pop();
	}
	while(!s.empty()){
		q.push(s.top());
		s.pop();
		if(!check_consecutive(q.front(),s.top())){
			cout << "\nfalse";
			return ;
		}
		q.pop();
		s.pop();
	}
	cout << "\nTrue";
	return;
}
