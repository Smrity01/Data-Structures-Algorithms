/*
Remove adjacent Duplicates from given string
Written By : Smrity Chaudhary
Dated 	   : 08/03/2019
*/
#include <iostream>
#include <stack>
using namespace std;

void removeDuplicates(char *input);
int main(){
    char input[50];
    cout << "enter string : ";
    cin >> input;
    removeDuplicates(input);
}

void removeDuplicates(char *input){
    char output[50];
    int outputptr = 0;
    output[0] = input[0];
    int i = 1;
    while(input[i] != '\0'){
        if(output[outputptr] == input[i]){
            if (outputptr - 1 >= 0){
                outputptr--;
            }
        }
        else{
            outputptr++;
            output[outputptr] = input[i];
        }
        i++;
    }
    output[outputptr+1] = '\0';
    i = 0;
    while(output[i] != '\0'){
        cout << output[i];
        i++;
    }
}
