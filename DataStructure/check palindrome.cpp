#include<iostream>
#include<conio.h>
#include<string>
#include<math.h>
#include<stack>
#include<queue>
using namespace std;

void check_palindrome(queue<char>,stack<char>);
int main(){
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


