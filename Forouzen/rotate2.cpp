/* left Rotate the array without extra variable
   Written by: Smrity Chaudhary
   Date : 30/12/2017
*/
#include<iostream>
using namespace std;

int rotate_list(int[],int);
void swapping(int&,int&);
int main(){
    int arr[]={4,6,8,2,6,5};
    cout << "Array after rotation: " ;
    rotate_list(arr,6);
    for(int i=0; i < 6; i++){
            cout << arr[i] << ",";
    }
    return 0;
}
int rotate_list(int arr[],int arr_size){
    for(int i = 0;i < arr_size-1; i++){
        swapping(arr[i],arr[i+1]);
    }
}
void swapping(int& num1,int& num2){
    num1 = num1 ^ num2;
    num2 = num1 ^ num2;
    num1 = num1 ^ num2;
}
