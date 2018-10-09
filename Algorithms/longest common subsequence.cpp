/*
Implementation of Longest common subsequence
Written By : Smrity Chaudhary
Dated      : 09/10/2018
*/
#include<iostream>
#include<vector>
using namespace std;

void longest_subsequence(vector<char>,vector<char>);
int main(){
    vector<char> seq1;
    vector<char> seq2;
    /*
    char character;
    char choice = 'y';
    while(choice == 'y' || choice == 'Y' ){
        cout << "Enter an character(sequence-1): ";
        cin >> character;
        seq1.push_back(character);
        cout << "Do you want to enter more?(y/n): ";
        cin >> choice;
    }
    choice = 'y';
    while(choice == 'y' || choice == 'Y' ){
        cout << "Enter an character(sequence-2): ";
        cin >> character;
        seq2.push_back(character);
        cout << "Do you want to enter more?(y/n): ";
        cin >> choice;
    }*/
    seq1.push_back('a');
    seq1.push_back('b');
    seq1.push_back('c');
    seq1.push_back('b');
    seq1.push_back('d');
    seq1.push_back('a');
    seq1.push_back('b');

    seq2.push_back('b');
    seq2.push_back('d');
    seq2.push_back('c');
    seq2.push_back('a');
    seq2.push_back('b');
    seq2.push_back('a');
    longest_subsequence(seq1,seq2);

}
void longest_subsequence(vector<char> seq1,vector<char> seq2){
    int size_seq1 = seq1.size();
    int size_seq2 = seq2.size();
    vector<char> subseq;
    int length[size_seq1+1][size_seq2+1];
    for(int i=0;i<=size_seq1;i++){
        for(int j=0;j<=size_seq2;j++){
        if(i==0 || j==0){
            length[i][j] = 0;
        }
        if(i>0 && j>0 && seq1[i-1]==seq2[j-1]){
            length[i][j] = 1+length[i-1][j-1];
        }
        if(i>0 && j>0 && seq1[i-1]!=seq2[j-1]){
            length[i][j] = max(length[i-1][j],length[i][j-1]);
        }
        }
    }
    cout << "\nmatrix is: \n";
    for(int i=0;i<=size_seq1;i++){
        for(int j=0;j<=size_seq2;j++){
            cout << length[i][j];
        }
        cout << "\n";
    }
    cout << " longest common subsequence is: \n";
    int i = size_seq1;
    int j = size_seq2;
    int index = size_seq1-1;
    vector<char> lcs;
    while(i>0&&j>0){
        if(seq1[i-1]==seq2[j-1]){
            lcs[index]= seq1[i-1];
            index--;
            i--;
            j--;
        }
        else if(length[i-1][j]>length[i][j-1]){
            i--;
        }
        else{
            j--;
        }
    }
    for(int i=0;i<lcs.size();i++){
        cout << lcs[i] << ",";
    }
}
