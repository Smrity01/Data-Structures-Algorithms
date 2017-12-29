/* Maximum of 3 elements using more than one if else
   Written by: Smrity Chaudhary
   Date : 29/12/2017
*/
#include<iostream>
using namespace std;

int maximum(int,int,int);
int max_of_two(int,int);
int main(){
    int num1;
    int num2;
    int num3;
    cout << "Enter first number: ";
    cin >> num1;
    cout << "\nEnter second number: ";
    cin >> num2;
    cout << "\nEnter third number: ";
    cin >> num3;
    cout << "\nMaximum number is: " << maximum(num1,num2,num3);
    return 0;
}
int maximum(int num1,int num2,int num3){

    if(num1 > num2 && num1 > num3){
        return num1;
    }
    else if (num2 > num3){
        return num2;
    }
    else{
       return num3;
    }

}
