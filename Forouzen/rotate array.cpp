/* left Rotate the array with extra variable
   Written by: Smrity Chaudhary
   Date : 30/12/2017
*/
#include<iostream>
using namespace std;

int rotate_list(int[]);
int main(){
    int arr[]={4,6,8,2,6,5};
    cout << "Array after rotation: " ;
    rotate_list(arr);
    for(int i=0;i<6;i++){
            cout << arr[i] << ",";

    }
    return 0;
}
int rotate_list(int arr[]){
    int temp = arr[0];
    for(int i=0;i<6;i++){
        arr[i] = arr[i+1];
    }
    arr[5]=temp;
}
