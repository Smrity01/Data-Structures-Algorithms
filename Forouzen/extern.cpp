#include<iostream>
using namespace std;

// variable declaration
extern int integer_var;
extern float float_var;
extern double double_var;
extern char char_var;

int main(){
	// variablr definition
	int integer_var;
	float float_var;
	double double_var;
	char char_var;
	// variable initialization 
	integer_var = 5667;
	float_var = 67.54;
	char_var = 'H';
	double_var = integer_var + float_var;
	cout << "\n *******Variable types*******";
	cout << "\n integer variable: " << integer_var;
    cout << "\n float variable: "	<< float_var;
	cout << "\n character variable: " << char_var;
	cout << "\n double variable: " << double_var;
	
return 0;
	
}