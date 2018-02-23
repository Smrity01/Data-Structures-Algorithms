#include<iostream>
using namespace std;

//variable declaration
	typedef int integer;
	typedef long int longint;
	typedef short int shortint;
	typedef signed int signint;
	typedef signed long int sign_longint;
	typedef signed short int sign_shortint;
	typedef  unsigned short int unsign_shortint;
	typedef unsigned long int unsign_longint;
	typedef bool boolean;
	
	int main(){
		// variable definition
		integer int_var;
		longint long_int_var ;
		shortint short_int_var;
		signint signed_int_var;
		sign_longint signed_longint_var;
		sign_shortint signed_shortint_var;
		unsign_shortint unsigned_shortint_var;
		unsign_longint unsigned_longint_var;
		boolean bool_var;
	    // variable intialization
		int_var = 78092;
		long_int_var = 889188;
		short_int_var = 86;
		signed_int_var = -8277877;
		signed_longint_var = -2977867;
		signed_shortint_var = -2767;
		unsigned_shortint_var = 2451;
		unsigned_longint_var = 45451945;
		bool_var = true;
		
		cout << "*******values of each variable******";
		cout << "\n integer variable: " << int_var;
		cout << "\n long integer variable: " << long_int_var;
		cout << "\n short integer variable: " << short_int_var; 
	    cout << "\n signed integer variable: " << signed_int_var;
		cout << "\n signed long integer variable: " << signed_longint_var;
		cout << "\n signed short integer variable: " << signed_shortint_var;
		cout << "\n unsigned short integer variable: " << unsigned_shortint_var;
		cout << "\n unsigned long integer variable: " << unsigned_longint_var;
		cout << "\n boolean variable: " << bool_var; 
	
	}