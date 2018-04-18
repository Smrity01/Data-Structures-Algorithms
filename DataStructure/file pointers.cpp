/*
Demonstrate the usage of tellg() , tellp() , seekp() and seekg()  function.
 Written By: Smrity Chaudhary
    Dated  : 18/04/2018
*/
#include<iostream>
#include<fstream>
#include<conio.h>
#include<string.h>
using namespace std;

int main(){
	/*
	Objective       : Read and write from file
	Input Parameter : None
	Output Parameter: Write file data on console
	Description     : Main function 
	Approach        : open file in write mode and write data in it then open file in read mode and read data from it and write
	                 it on console.
	*/
	string line;
	cout << "\nWrite in file.....\n";
	ofstream file("alphabet.txt");
	file << "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	cout << "\nCurrent position: " << file.tellp();
	file.seekp(0,ios::beg);                           //Usage of seekp
	cout << "\nposition after using seekp: " << file.tellp();
	file.close();
	cout << "\nRead from file.....\n";
	ifstream myfile("alphabet.txt");                  // open file in read mode
	cout << "\nposition After opening in read mode: " << myfile.tellg();
	myfile.seekg(0,ios::end);                        //Usage seekg
	cout << "\nposition after using seekg: " << myfile.tellg();
	myfile.seekg(0,ios::beg);
	char ch;
	while(!myfile.eof()){                 //get data from file and write it on console
		cout << "\nAt this position: " << myfile.tellg();
		myfile >> ch;
		cout << "\ncureent character: " << ch;
	}
	myfile.close();                           //close file
	getch();
	return 0;
}

