/*
Implement Equivalence tester for bank
Written By: Smrity Chaudhary
Dated     : 17/11/2018
*/
#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

void invoke_tester();
vector< pair<int,int> > input();
bool equivalence_tester(int,int);
int main(){
    /*
    Objective       : To call the function with main algorithm.
    Input Parameter : None
    Description     : Driver function of the program.
    */
    invoke_tester();
}
void invoke_tester(){
    /*
    Objective       : To Invoke the Equivalence tester function for.
    Input Parameter : None
    Output Value    : Whether there are more than n/2 equivalent or not.
    Description     : First sort the given account number list. Then count the
                      equivalent account numbers. if it reaches more than n/2 then
                      print the result.
    */
    vector< pair<int,int> > card_list;
    card_list = input();
    if(card_list.size()<2){
        cout << "\nThere must be atleast 2 entries...!";
        return;
    }
    cout << "\nAccount Number || card Number\n";
    for (int i=0;i<card_list.size();i++){
        cout << "\n" << card_list[i].first << "           "
             "            " << card_list[i].second;
    }
    sort(card_list.begin(),card_list.end());
    bool flag;
    int counter = 1;
    for(int i=0;i<card_list.size()-1;i++){
        flag = equivalence_tester(card_list[i].first,card_list[i+1].first);
        if(flag == 1){
            counter++;
        }
        else{
            counter = 1;
        }
        if(counter > card_list.size()/2){
            cout << "\nMore than n/2 cards that are equivalent to one another. ";
            return;
        }
    }
    cout << "\nLess than n/2 cards has equivalent.";
    return;

}
vector< pair<int,int> > input(){
    /*
    Objective       : To Take input from user.
    Input Parameter : None
    Description     : Take input from user and return data to calling function.
    */
    vector< pair<int,int> > card_detail;
    pair <int,int> number;
    int counter;
    cout << "........How many card information do you want to Enter: ";
    cin >> counter;
    cout << "\n\n";
    while (counter != 0){
        cout << "\nEnter the account number: ";
        cin >> number.first;
        cout << "\nEnter the Card number: ";
        cin >> number.second;
        card_detail.push_back(number);
        counter = counter-1;
        cout << counter;
    }
    return card_detail;
}
bool equivalence_tester(int value1,int value2){
    /*
    Objective       : To Check whether the given account numbers are equivalent or not.
    Input Parameter : Two Account numbers
    Return Value    : True or False
    Description     : Simple equate the two values and return true if they are equal.
    */
    if(value1==value2){
        return true;
    }
    else{
        return false;
    }
}
