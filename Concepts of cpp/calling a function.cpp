/*
 call be reference, call by value and default parameter 
 Written By: Smrity Chaudhary
 Dated     : 1/08/2018 
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
	int p = 20,q = 23;
	q = func(p,q);
	cout << p <<","<<q<<"\n";
	p = func(q);
	cout << p <<","<<q<<"\n";
	q = func(p);
	cout << p <<","<<q<<"\n";
	return 0;
}
