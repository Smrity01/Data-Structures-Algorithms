/* Segregate the zero's or one in an array
   Written by: Smrity Chaudhary
   Date :  10/01/2018
*/
#include<iostream>
#include<cstdlib>
using namespace std;

int find_pair(int*,int);
int main(){
    int len;
    cout << "Enter a size of array: ";
    cin >> len;
    int arr[len];

    cout << "Enter elements of array: ";
    for(int i = 0; i < len;i++){
        cin >> arr[i];
    }
    find_pair(arr,len);
    return 0;
}
int find_pair(int* arr,int len){
    int pos = 0;
    int track ;
    int prev ;
    while( pos < len ){
        track = pos + 1;
        if (prev != abs(arr[pos]) ){
        while(track < len ){
            if(arr[pos]+arr[track] == 0 ){
                cout <<"Pair with sum 0: "<< arr[pos] << " & " <<arr[track] <<endl;
                prev = abs(arr[track]);
                break;
            }
            else{
                track++;
            }
        }
    }
    pos++;
}
}
