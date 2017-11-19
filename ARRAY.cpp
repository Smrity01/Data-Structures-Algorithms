#include<iostream>
using namespace std;

int main(){
	// array initilization
	int integer_array[5] = {6,7,8,9};
	// array declaration
	char character_array[5]; 
	// array assignment
	character_array[0] = 'a'; 
    character_array[1] = 'b'; 
	character_array[2] = 'c';
	character_array[3] = 'd'; 
	character_array[4] = 'e';
		int ascii_array['A'];
		ascii_array[0] = 7;
	
	cout << "\n Size of integer array: " << sizeof(integer_array);
	cout << "\n Size of integer array element: " << sizeof(integer_array[0]);
    cout << "\n Value of integer_array[0]: " << integer_array[0];
	cout << "\n Value of integer_array[4] : " << integer_array[4];
	cout << "\n Size of character array: " << sizeof(character_array);
	cout << "\n Size of character array element: " << sizeof(character_array[0]);
	cout << "\n Size of ascii_array : " << sizeof(ascii_array);
	cout << "\n Value of ascii_array[0] : " << ascii_array[0];
	cout << "\n Value of ascii_array[1] : " << ascii_array[1];
	return 0;
}