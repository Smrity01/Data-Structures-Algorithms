/*
Check the palindrome using STL Stack and Queue
Written By : Smrity Chaudhary
  Dated    : 14/03/2018 
*/
#include<iostream>
#include<conio.h>
#include<string>
#include<math.h>
#include<stack>
#include<queue>
using namespace std;

void check_palindrome(queue<char>,stack<char>);
int main(){
  /*
  Objective       : Create Object of stack and Queue class and take input from user
  Input Parameter : None
  Output Parameter: None
  Description     : Main function
  Approach        : Take string from user and push one by one character of string into stack and Queue using for loop 
  */
  queue <char> object;
  stack <char> s;
  string word;
  cout <<" Enter a word: ";
  cin >> word;
  int len;
  len = word.length();
  for (int i=0;i<len;i++) {
    object.push(word[i]);
    s.push(word[i]);
	}
  check_palindrome(object,s);
  getch();
  return 0;
}
void check_palindrome(queue<char> q,stack<char> s) {
   /*
  Objective       : CHeck whether the string is a palindrome or not
  Input Parameter : object of Queue and Stack class  
  Output Parameter: Print the status of string
  Description     : Void function
  Approach        : Pop one by one character of string from (last character) Stack and (first character) Queue using while loop and compare them 
  */
  while(!s.empty()){
	if(q.front()!=s.top()){
		cout << "\nIts NOT a PALINDROME..";
		return;
	}
	s.pop();
	q.pop();
 }
 cout << "Its a PALINDROME..";
return;	
}
