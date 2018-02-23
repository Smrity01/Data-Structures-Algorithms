#include<iostream>
using namespace std;
#include<stack>

int main(){
  /*
  Objective       :To reverse the user entered numbers using stack
  Input parameter : None
  Return value    : None
  */
  stack <int> s;
  int count;
  cout <<" How many elements do you want to enter: ";
  cin >> count;
  int element;
  for (int i;i<count;i++){
    cout << "\nEnter element: ";
    cin >> element;
    s.push(element);
  }
  cout << "\nReversed order.....\n";
  while (!s.empty()){
  	cout << s.top() <<",";
  	s.pop();
  }
  return 0;
}
