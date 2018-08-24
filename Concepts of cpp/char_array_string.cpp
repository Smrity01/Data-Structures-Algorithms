/*
 Char, string and array
 Written By: Smrity Chaudhary
 Dated     : 3/08/2018
*/
#include<iostream>
#include<string>
using namespace std;

int main(){
	//char name[10] = 'smrity'; ERROR: double quotes must be there
	//char grade = 'A+'; ERROR overflow,it can store only one char
	//char grade = "A"; ERROR invalid conversion
	char grade = 'A';
	grade = 'B';
	char name[7] = "smrity";
	string course = "mca second year...";
	char last_name[] = {'c','h','a','u','d','h','a','r','y','\0'}; //can be initialize without null but will give garbage at the end
	cout << name << " " << grade << " " << last_name;
	cout << "\n"<< sizeof(name) << " name: "<< name[6]<<"\n" << course << "\nsize:" << course.length();
	//int marks[5] = {1,2}; fill 1 and 2 at first two place rest with zero
	//int marks[5] = {0};fill 0 at first place rest with zero also
	//int marks[] = {1};fill 1 at first place rest with garbage value
	//int marks[5]; garbage value
	int marks[5] = {}; //fill all places with zero
	cout << "\n" << marks[0] << "," << marks[1] << "," << marks[2] << "," << marks[3] << "," << marks[4];
	return 0;
}
