#include<iostream>
#include<vector>
using namespace std;

void edit_distance(vector<char>,vector<char>);
int main(){
    vector<char> converting;
    vector<char> converted;
    char choice = 'y';
    char element;
    /*
    cout << "Enter the elements for the string you want to convert.";
    while (char == 'y'){
        cout << "enter the element: ";
        cin >> element;
        converting.push_back(element);
        cout << "Do you want to enter more(y/n): ";
        cin >> choice;
    }
    cout << "Enter elements for the string in which you want to convert.\n";
    while (char == 'y'){
        cout << "enter the element: ";
        cin >> element;
        converted.push_back(element);
        cout << "Do you want to enter more(y/n): ";
        cin >> choice;
    }
    */
    converted.push_back('a');
    converted.push_back('b');
    converted.push_back('c');
    converted.push_back('f');
    converted.push_back('g');
    converting.push_back('a');
    converting.push_back('d');
    converting.push_back('c');
    converting.push_back('e');
    converting.push_back('g');
    edit_distance(converting,converted);
    return 0;
}
void edit_distance(vector<char> converting,vector<char> converted){
    int row = converting.size();
    int col = converted.size();
    int table[row+1][col+1];
    table[0][0] = 0;
    for (int i=0;i<=row;i++){
        for (int j=0;j<=col;j++){
            if(i==0 && i<j){
                table[i][j] = table[i][j-1]+1;
            }
            if(j==0 && j<i){
                table[i][j] = table[i-1][j]+1;
            }
            if(i>0 && j>0){
                if(converting[i-1] == converted[j-1]){
                    table[i][j] = table[i-1][j-1];
                }
                else{
                        int temp = min(table[i-1][j],table[i][j-1]);
                    table[i][j] = min(temp,table[i-1][j-1]) + 1;
                }
            }
        }
    }
    for (int i=0;i<=row;i++){
        for (int j=0;j<=col;j++){
                cout << table[i][j] << " ";
        }
        cout << "\n";
    }
}
