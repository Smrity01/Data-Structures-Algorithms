/*
Given a string, find the rank of the string amongst its permutations sorted lexicographically. 
Assume that no characters are repeated.

Example :

Input : 'acb'
Output : 2

The order permutations with letters 'a', 'c', and 'b' : 
abc
acb
bac
bca
cab
cba
*/
#include<iostream>
#include<string.h>
#include<string>
using namespace std;

void setCount(int *countArray, string A);
int findRank(string A);
int factorial(int number);
void updateCount(int *countArray, char currentChar);
int main(){
    string A = "acb";
    cout << findRank(A);
}
int findRank(string A){
    int countCharacterArray[CHAR_MAX];
    setCount(countCharacterArray, A);
    int rank = 1;
    int leftPermutations = factorial(A.length());
    cout << "length!:  "<<leftPermutations << endl;
    int smallerCount = 0;
    for (int i = 0; i < A.length(); i++){
        leftPermutations = leftPermutations / (A.length() - i);
            cout << "length!:  "<<leftPermutations << endl;
        smallerCount = countCharacterArray[A[i] - 1];
            cout << "smallercount:  "<<smallerCount << endl;
        rank  =  rank + smallerCount * leftPermutations;
        updateCount(countCharacterArray, A[i]);
    }
    return rank;
}
void setCount(int *countArray, string A){
    for (int i = 0; i < CHAR_MAX; i++){
        countArray[i] = 0;
    }
    for (int  i = 0; i < A.length(); i++){
        ++countArray[A[i]];
    }
    for (int  i = 1; i < CHAR_MAX; i++){
        countArray[i] += countArray[i - 1];
    }
}
int factorial(int number){
    if (number <= 1){
        return 1;
    }
    return number * factorial(number - 1);
}
void updateCount(int *countArray, char currentChar){
    for (int i = currentChar; i < CHAR_MAX; i++){
        countArray[i] = countArray[i] - 1;
    }
}