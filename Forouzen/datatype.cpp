#include<iostream>
using namespace std;

int main(){
	
	//variable declaration
	int integer_variable;
	long int long_int_variable;
	short int short_int_variable;
	signed int signed_int_variable;
	signed long int  signed_long_int_variable;
	signed short int signed_short_int_variable;
	unsigned short int unsigned_short_int_variable;
	unsigned long int unsigned_long_int_variable;
	char char_variable;
	unsigned char unsigned_char_variable;
	signed char signed_char_variable;
	float float_variable;
    	double double_variable;	
	long double long_double_variable; 
	bool bool_variable;
	
	//array declaration
	int integer_array;
	long int long_int_array[10];
	short int short_int_array[10];
	signed int signed_int_array[10];
	signed long int  signed_long_int_array[10];
	signed short int signed_short_int_array[10];
	unsigned short int unsigned_short_int_array[10];
	unsigned long int unsigned_long_int_array[10];
	char char_array[10];
	unsigned char unsigned_char_array[10];
	signed char signed_char_array[10];
	float float_array[10];
    	double double_array[10];	
	long double long_double_array[10]; 
	bool bool_array[10];
	
	//Printing the size of variables of different data types............
	cout << " \n Printing the size of variables of different data types............ \n";
	cout << " \n size of int_variable: "         << sizeof(integer_variable);
	cout << " \n size of long_int_variable: "    << sizeof(long_int_variable);
	cout << " \n size of short_int_variable: "   << sizeof(short_int_variable);
	cout << " \n size of signed_int_variable: "  << sizeof(signed_int_variable);
	cout << " \n size of signed_long_int_variable: " << sizeof(signed_long_int_variable);
	cout << " \n size of signed_short_int_variable: " << sizeof(signed_short_int_variable);
	cout << " \n size of unsigned_short_int_variable: " << sizeof(unsigned_short_int_variable);
	cout << " \n size of unsigned_long_int_variable: " << sizeof(unsigned_long_int_variable);
	cout << " \n size of char_variable: "          << sizeof(char_variable);
	cout << " \n size of unsigned_char_variable: " << sizeof(unsigned_char_variable);
	cout << " \n size of signed_char_variable: "   << sizeof(signed_char_variable);
	cout << " \n size of float_variable: "         << sizeof(float_variable);
    	cout << " \n size of double_variable: "        << sizeof(double_variable);	
	cout << " \n size of long_double_variable: "   << sizeof(long_double_variable); 
	cout << " \n size of bool_variable: "          << sizeof(bool_variable);
	
	//Printing the size of arrays of different data types............ 
	cout << " \n Printing the size of arrays of different data types............\n";
	cout << " \n size of int_array: "         << sizeof(integer_array);
	cout << " \n size of long_int_array: "    << sizeof(long_int_array);
	cout << " \n size of short_int_array: "   << sizeof(short_int_array);
	cout << " \n size of signed_int_array: "  << sizeof(signed_int_array);
	cout << " \n size of signed_long_int_array: " << sizeof(signed_long_int_array);
	cout << " \n size of signed_short_int_array: " << sizeof(signed_short_int_array);
	cout << " \n size of unsigned_short_int_array: " << sizeof(unsigned_short_int_array);
	cout << " \n size of unsigned_long_int_array: " << sizeof(unsigned_long_int_array);
	cout << " \n size of char_array: "          << sizeof(char_array);
	cout << " \n size of unsigned_char_array: " << sizeof(unsigned_char_array);
	cout << " \n size of signed_char_array: "   << sizeof(signed_char_array);
	cout << " \n size of float_array: "         << sizeof(float_array);
    	cout << " \n size of double_array: "        << sizeof(double_array);	
	cout << " \n size of long_double_array: "   << sizeof(long_double_array); 
	cout << " \n size of bool_array: "          << sizeof(bool_array);
	
return 0;	
	
}
