/*
Balanced parentheses using STL stack
ASSUMPTION : IF THERE ARE NO PARENTHESES IN THE EXPRESSION, THEN IT WILL BE
                CONSIDERED 'BALANCED'
Written By : Smrity Chaudhary
Dated      : 06/02/2019
*/
#include<bits/stdc++.h>
#include<stack>
using namespace std;

char validClosing(char openingdelimeter);
bool isCloseParenthesis(char delimeter);
bool isOpenParenthesis(char delimeter);
bool balancedParentheses(string parenthesis);
void checkParentheses();
int main() {
    // Call driver function of this problem.
    checkParentheses();
}
void checkParentheses() {
    /*
    - Take Input as string of Expressions.
    - Call the function to check if parentheses in expression are balanced or
        not.
    - Print the Output.
    */
    string parentheses;
    cout << "Enter the Expresion: ";
    cin >> parentheses;
    if (balancedParentheses(parentheses))
        cout << "Balanced :)";
    else
        cout << "'NOT' Balanced :(";
}
bool balancedParentheses(string parentheses) {
    /*
    - The opening parenthesis will be pushed into stack.
    - All other symbols in the expressions will be ignored.
    - If current parenthesis is closing delimeter and stack is empty OR it
      doesn't match with the closing bracket of top symbol then false
        will be returned otherwise pop the stack and move on.
    */
    if (parentheses.size() == 0)
        return true;
    stack<char> mystack;
    for (int itr = 0; itr < parentheses.size(); itr++) {
        if (isOpenParenthesis(parentheses[itr])) {
            mystack.push(parentheses[itr]);
        }
        else if (isCloseParenthesis(parentheses[itr])) {
            if (mystack.empty())
                return false;
            if (parentheses[itr] != validClosing(mystack.top())) {
                return false;
            }
            else{
                mystack.pop();
            }
        }
    }
    if (!mystack.empty())
        return false;
    else
        return true;
}
bool isOpenParenthesis(char delimeter) {
    /*
    Check if given symbol is an opening parenthesis or not.
    */
    if (delimeter == '(' || delimeter == '[' || delimeter == '{') {
            return true;
        }
    return false;
}
bool isCloseParenthesis(char delimeter) {
    /*
    Check if given symbol is a closing parenthesis or not.
    */
    if (delimeter == ')' || delimeter == ']' || delimeter == '}') {
            return true;
        }
    return false;
}
char validClosing(char openingdelimeter) {
    /*
    Return closing bracket of opening parenthesis.
    */
    if (openingdelimeter == '(')
        return ')';
    else if (openingdelimeter == '[')
        return ']';
    else
        return '}';
}
