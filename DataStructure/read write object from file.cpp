/*
Write and read object using read write function
 Written By: Smrity Chaudhary
    Dated  : 18/04/2018
*/
#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

class Student{
	/*
	Objective       : Create a Class Student
	Input Parameter : None
	Output Parameter: None
	Description     : Class definition
	Approach        : Class definition provides data member and member functions for the Student class
	*/
	private:
		int rollno;
		char name[30];
		char course[10];
	public:
		void getdata();
		void displaydata();
};
void Student::getdata(){
	/*
	Objective       : Create a member function of Student Class
	Input Parameter : None
	Output Parameter: None
	Description     : Member function definition
	Approach        : Take student data
	*/
	cout << "Enter your roll number: ";
	cin >> rollno;
	cout << "Enter your Name: ";
	cin >> name;
	cout << "Enter your Course(MCA/MSc): ";
	cin >> course;
}
void Student::displaydata(){
	/*
	Objective       : Create a member function of Student Class
	Input Parameter : None
	Output Parameter: None
	Description     : Member function definition
	Approach        : Display Student data
	*/
	cout << "\n\nRoll NO.: " << rollno;
	cout << "\nName    : " << name;
	cout << "\nCourse  : " << course;
}
int main(){
	/*
	Objective       : Read and write object from file
	Input Parameter : None
	Output Parameter: None
	Description     : Main function 
	Approach        : Open file in write mode and write object in it .
	*/
	string line;
	Student object;
	ofstream wfile ("student.txt",ios::app);
	if(!wfile){
		cout << "ERROR: File not found...";
	}
	object.getdata();
	wfile.write((char*)&object,sizeof(object));
	wfile.close();
	//cout << "\nData in your file...";
	ifstream rfile ("student.txt",ios::in);
	if(!rfile){
		cout << "ERROR: File not found...";
	}
	while((rfile.read((char*)&object,sizeof(object)))!=NULL){
		object.displaydata();
	}
	rfile.close();
	return 0;
}
