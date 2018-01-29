/*
Sequential search
   written by : Smrity Chaudhary
   Dated      : 29/01/18
*/
#include<iostream>
using namespace std;

int Sequential_search(int*,int,int);
int main(){
    int len;
    cout << "Enter the size of array: ";
    cin >> len;
    int arr[len];
    for (int i=0; i < len; i++){
        cout << "Enter elements of array: ";
        cin >> arr[i];
    }
    int element;
    cout << "Enter the element you want to search:  ";
    cin >> element;
    int index = Sequential_search(arr,len,element);
    if( index > 0){
            cout << "\n element found at " <<index ;
    }
    else{
            cout << "\n element not found..."  ;
    }
}
int Sequential_search(int* arr,int len,int element){
    int counter = 0;
    while(counter < len){
        if(element == arr[counter]){
            return counter;
        }
        counter++;
    }
    return 0;
}
