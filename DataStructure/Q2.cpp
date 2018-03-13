#include<iostream>
#include<conio.h>
#include<math.h>
#include<stack>
#include<queue>
using namespace std;

bool check_consecutive(int,int);
void all_consecutive(stack<int>);
int main(){
  stack <int> s;
  int count;
  cout <<" How many elements do you want to enter: ";
  cin >> count;
  int element;
  for (int i;i<count;i++) {
    cout << "\nEnter element: ";
    cin >> element;
    s.push(element);
  }
  all_consecutive(s);
  getch();
  return 0;
}

bool check_consecutive(int num1,int num2){
	if(fabs(num1-num2)==1){
		return true;
	}
	else{
	 return false;
	 }
}

void all_consecutive(stack<int> s){
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
