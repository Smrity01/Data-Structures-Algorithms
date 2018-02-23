/*
Infix to postfix conversion
Written by : Smrity Chaudhary
     Dated : 21-02-2018
*/
#include<iostream>
#include<cstring>
using namespace std;
#include<stack>

int precedence(char oper){
	/*
	Objective       : To check the precedence of current operator 
	Input parameter : Current operator of expression
	Return value    : Precedence of operator 
	*/
	if (oper == '^'){
		return 3;
	}
	else if (oper == '*' || oper == '/'){
		return 2;
	}
	else if (oper == '+' || oper == '-'){
		return 1;
	}
	else{
		return 0;
	}
}
void infix_to_postfix(string str ){
	/*
	Objective       : Convert the infix expression to postfix expression 
	Input parameter : String of expression
	Output value    : Print the postfix expression
	*/
	stack <char> s;
	int len = str.length();
	for (int i; i<len; i++){
		if (str[i]=='*' || str[i]=='/' || str[i]=='^' || str[i]=='+' || str[i]=='-'){
		
			if(!s.empty() && precedence(s.top()) > precedence(str[i])){
				cout << s.top();
				s.pop();
				s.push(str[i]);	
			}
			else{
				s.push(str[i]);
			}			
		}
		else{
			cout << str[i];
		}
	}
	while(!s.empty()){
				cout << s.top();
				s.pop();
			}
}
int main(){
	/*
	Objective       : Call infix_to_postfix function 
	Input parameter : None
	Output value    : None
	*/
	string str;
	str = "a+b-c/d";
	cout << "infix expression: " << str;
	cout << "\nPostfix expression: ";
	infix_to_postfix(str);
}
