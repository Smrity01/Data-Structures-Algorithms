/*
 Two way calling function with array
 Written By: Smrity Chaudhary
 Dated     : 3/08/2018
*/
#include<iostream>
#include<string>
using namespace std;

void display_one(int a[]);
void display_two(int* a);
int main(){
	int a[]={1,2,3,4,5,6};
	display_one(a);
	display_two(a);
	return 0;
}
void display_one(int a[]){
	for(int i=0;i<6;i++){
		cout << a[i] << "\n";
	}
}
void display_two(int* a){
	for(int i=0;i<6;i++){
		cout << a[i] << "\n";
	}
}

