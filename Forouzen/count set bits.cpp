/*
Calculate the set bits in a number
   written by: Smrity chaudhary
   Date : 5-01-2018
*/
#include<iostream>
using namespace std;

int power(int);
int binary(int);
int calculate(int);
int main(){
    int num =4&3;
    cout << "Enter a number: ";
    cin >> num;
    cout << "Number of set bits: "<< binary(num);
}
int binary(int num){
    if (num != 0 && num == power(num)){
        return 1;
    }
    else{
    return (calculate(num));}

}
int power(int num){
    return (num & ~(num-1));
}
int calculate(int num){
    int total = 0;
    int prev = num;
    int temp = num;
    while(temp!=0){
            temp = temp & num-1;
            num = num - 1;
            if(temp != prev){
                total++;
            }
            prev = temp;
    }

    return total;
}
