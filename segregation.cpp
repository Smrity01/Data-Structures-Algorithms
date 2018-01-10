/* Segregate the zero's or one in an array
   Written by: Smrity Chaudhary
   Date :  10/01/2018
*/
#include<iostream>
using namespace std;

int segregate(int*,int);
void swapping(int&,int&);
int main(){
    int len;
    cout << "Enter a size of array: ";
    cin >> len;
    int arr[len];

    cout << "Enter elements of array: ";
    for(int i = 0; i < len;i++){
        cin >> arr[i];
    }
    segregate(arr,len);
    cout << "segregated array :";
    for(int i = 0; i < len;i++){
        cout << arr[i]<<",";
    }
    return 0;
}
int segregate(int* arr,int len){
    int pos = 0;
    int last = len-1;
    while(pos < last){
        if (arr[pos] == 1){
             swapping(arr[pos],arr[last]);
             last--;
        }
        else{
            pos++;
        }
    }
}
void swapping(int& num1,int& num2){
    num1 = num1 ^ num2;
    num2 = num1 ^ num2;
    num1 = num1 ^ num2;
}
