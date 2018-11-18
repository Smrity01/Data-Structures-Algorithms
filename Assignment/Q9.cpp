/*
Algorithm to decide the order of people
Written By : Smrity Chaudhary
Dated      : 18/11/2018
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool selectColumn(const vector<int>&, const vector<int>&);
void input();
void display(vector< vector<int> >);
int main(){
    input();
    return 0;
}
bool select_column(const vector<int>& v1, const vector<int>& v2){
    /*
    objective        : To select column by which sorting can be applied
    Input parameter  : None
    Output parameter : True or false
    Description      : Simple If condition
    */
    if(v1[1] < v2[1]){
        return true;
    }
    else{
        false;
    }
}
void decide_order(vector<vector<int> > &data){
    /*
     Objective        : To decide the order.
     Input parameter  : None
     Output parameter : None
     Description      : Sorting according to swim time and displaying order.
     */
    sort(data.begin() , data.end() , select_column );
    cout << "\nFollowings are the order of contestants for small completion time\n\n";
    for (int i = 0; i < data.size(); i++) {
        cout << data[i][0] << ", ";
    }
    cout << endl;
}

void display(vector< vector<int> > data){
    /*
    Objective        : Print the data.
    Input parameter  : None
    Output parameter : None
    Description      : Display using for loop.
     */
    cout << "\nContestant No. | Swim Time | Bike Time | Run Time\n";
    for ( int i = 0; i < data.size(); i++ ) {
        cout << "          " << data[i][0] << "    |     " << data[i][1] << "     |    "
        << data[i][2] << "    |     " << data[i][3];
        cout << endl;
    }

}

void input() {
    /*
    Objective        : To insert the data and call member functions
    Input parameter  : None
    Output parameter : None
    Description      : Insertion using loop and then calling member functions.
    */
    int contestant;
    cout << "\nEnter Number of contestants: ";
    cin >> contestant;
    vector< vector<int> > data(contestant);
    cout << "\nEnter Swim Time , Bike Time and then Run Time(Respectively)\n";
    for ( int i = 0; i < contestant; i++) {
        data[i] = vector<int>(4);
        data[i][0] = i + 1;
        cin >> data[i][1];
        cin >> data[i][2];
        cin >> data[i][3];
    }
    display(data);
    decide_order(data);
    data.clear();
}
