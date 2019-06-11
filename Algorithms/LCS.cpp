/*
Longest common subsequence.
*/
#include<iostream>
#include<vector>
using namespace std;

void printLCS(vector<char> X, vector<char> Y, int **lengthMatrix, int rows, int cols);
int lengthOfLCS(vector<char> X, vector<char> Y);
int main(){
    vector<char> X;
    X.push_back('A');
    X.push_back('B');
    X.push_back('C');
    X.push_back('B');
    X.push_back('D');
    X.push_back('A');
    X.push_back('B');
    vector<char> Y;
    Y.push_back('A');
    Y.push_back('B');
    Y.push_back('F');
    Y.push_back('A');
    Y.push_back('B');
    Y.push_back('A');
    cout << "\nLength of LCS: " << lengthOfLCS(X,Y);
}
int lengthOfLCS(vector<char> X, vector<char> Y){
    if (X.size() < 1 || Y.size() < 1){
        return 0;
    }
    int rows = X.size() + 1;
    int cols = Y.size() + 1;
    int **lengthMatrix = new int*[rows];
    for (int i = 0; i < rows; i++){
        lengthMatrix[i] = new int[cols];
    }
    for (int i = 0; i < rows; i++ ){
        lengthMatrix[i][cols - 1] = 0;
        //cout << lengthMatrix[i][m-1] << endl;
    }
    for (int i = 0; i < cols; i++ ){
        lengthMatrix[rows - 1][i] = 0;
    }
    for (int i = rows - 2; i >= 0; i--){
        for (int j = cols - 2; j >= 0; j--){
            //cout << "i " << i << ",j " << j << endl;
            lengthMatrix[i][j] = lengthMatrix[i + 1][j + 1];
            if (X[i] == Y[j]){
                lengthMatrix[i][j]++;
            }
            if (lengthMatrix[i][j] < lengthMatrix[i + 1][j]){
                lengthMatrix[i][j] = lengthMatrix[i + 1][j];
            }
            if (lengthMatrix[i][j] < lengthMatrix[i][j + 1]){
                lengthMatrix[i][j] = lengthMatrix[i][j + 1];
            }
        }
    }
    printLCS(X, Y, lengthMatrix, rows, cols);
    return lengthMatrix[0][0];
}
void printLCS(vector<char> X, vector<char> Y, int ** lengthMatrix, int rows, int cols){
    int i = 0, j = 0;
    while( i < rows - 1 && j < cols - 1){
        if (X[i] == Y[j]){
            cout << X[i] << " ";
            i++;
            j++;
        }
        else if( lengthMatrix[i + 1][j] >= lengthMatrix[i][j]){
            i++;
        }
        else{
            j++;
        }
    }
}