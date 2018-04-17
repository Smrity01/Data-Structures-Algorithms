/*
Write and read values using variables in/from file
 Written By: Smrity Chaudhary
    Dated  : 17/04/2018
*/
#include<iostream>
#include<fstream>
#include<conio.h>
#include<string.h>
using namespace std;

int main(){
	char poetname[30];
	char poemname[30];
	string line;
	ofstream file ("life.txt",ios::app);
	if(!file){
		cout << "ERROR: File not found...";
		return 0;
	}
	cout << "\nEnter Poet name: ";
	cin >>  poetname;
	cout << "\nEnter Poem name: ";
	cin >>  poemname;
	file << "\n- " <<poemname << "\n- " << poetname;
	file.close();
	cout << "\nRead from file.....\n";
	ifstream myfile("life.txt");
	while(getline(myfile,line)){
		cout << line <<"\n";
	}
	myfile.close();
	getch();
	return 0;
}

