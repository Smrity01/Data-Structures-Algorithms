/*
calculate the sum of long array elements
  written by: smrity chaudhary
  date: 4/01/2018
*/
#include<iostream>
using namespace std;

int main(){
    int length;
    cout << "Enter the size of array: ";
    cin >> length;
    long long int arr[length];
    cout << "Enter the array elements: ";
    for(int i=0; i < length; i++){
            cin >> arr[i];
    }
    long long int sum = 0;
        for(int i=0; i < length; i++){
            sum = sum + arr[i];
    }
    cout <<"sum of array: "<<sum;
}
