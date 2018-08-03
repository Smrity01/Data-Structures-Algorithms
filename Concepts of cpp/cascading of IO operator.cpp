/*
 Cascading of I/O operator and calculation of expression
 Written By: Smrity Chaudhary
 Dated     : 2/08/2018
*/
#include<iostream>
using namespace std;

int main(){
	int var = 10;
	int test_var = var++ + ++var + ++var + var; 
	// All prefix are computed and expression is evaluated, then postfix are computed 
	cout << test_var << "\n" << var << "\n";
	int value = 5;
	cout << ++value <<"," << value <<"," << value++ <<"\n"; 
	//Print from left to right but calculation is compiler dependent
	var = 5;
	value = 5;
	int x = 10;
	cout << x + ++value + value++ * ++var /var++ ;
	cout << "\n" << value << "," << var;
	float amount = 12.6;
	//ERROR: % is not a real airthmetic operator
	//cout << "\n % operator on real number:" << amount%2;
	return 0;
}
