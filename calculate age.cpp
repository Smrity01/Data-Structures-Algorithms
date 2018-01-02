/* Calculate the age of a person
   Written by: Smrity Chaudhary
   Date : 28/12/2017
*/
#include<iostream>
#include<cstdlib>
using namespace std;

void get_date(int&,int&,int&);
int calculate(int,int);
int main(){
   int current_month;
   int current_day;
   int current_year;
   cout << "\n..........Current date.......";
   get_date(current_month,current_day,current_year);
   int birth_month;
   int birth_day;
   int birth_year;
   cout << "\n..........your date of birth.......";
   get_date(birth_month,birth_day,birth_year);
   int age;
   age = calculate(current_year,birth_year);
   cout << "\nYour age is: " << abs(age) << endl;
   //cout << endl << month <<"/" << day<<"/" <<year;
   return 0;

}
void get_date(int& month,int& day,int& year){
   cout << "\nEnter the dates(month day year...seperated by space..): ";
   std::cin >> month;
   std::cin >> day;
   std::cin >> year;
}
int calculate(int curr,int birth){
  return (birth-curr);
}
