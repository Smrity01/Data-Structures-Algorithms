/*
 constant variable
 Written By: Smrity Chaudhary
 Dated     : 2/08/2018
*/
#include<iostream>
using namespace std;

int func(int &x,int y=10){
	if(x%y == 0){
		return ++x;
	}
	else{
		return y--;
	}
}
int main(){
	const int p = 5; // constant variable should be initialised at the time of
	                 //declaration otherwise its an ERROR

	int q = 23;
	q = func(q,p);
	cout << p <<","<<q<<"\n";
	//p = func(q);       ERROR: Assignment of Read only p
	cout << p <<","<<q<<"\n";
	//q = func(p);       ERROR: Constant vairable cannot be passed as
	                     //referenced parameter,it will give you an error.
	cout << p <<","<<q<<"\n";
	return 0;
}
