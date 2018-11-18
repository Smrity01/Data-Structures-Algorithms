/*
Maximize profit for stock price
Written By: Smrity Chaudhary
Dated     : 18/11/2018
*/
#include<iostream>
#include<vector>
using namespace std;

//Structure to store the buying and selling day.
struct investmentday{
    int buy_day;
    int sell_day;
};
vector< int > input();
void investment();
int main(){
    /*
    Objective       : To call the function with main algorithm.
    Input Parameter : None
    Description     : Driver function of the program.
    */
    investment();
}
vector< int > input(){
    /*
    Objective       : To Take input from user.
    Input Parameter : None
    Description     : Take input from user and return data to calling function.
    */
    vector< int > details;
    int price;
    int num_days;
    cout << "How many days...: ";
    cin >> num_days;
    int day = 1;
    while (num_days!=0){
        cout << "Enter price for day "<< day << ": ";
        cin >> price;
        day++;
        details.push_back(price);
        num_days--;
    }
    return details;
}

void investment(){
    /*
    Objective       : To Find best day for investment to get maximum profit.
    Input Parameter : None
    Description     : It will fill find the maximum difference found so far and
                      minimum number visited so far. Store the buying day and
                      selling day into structure variable.
    */
    vector< int > details;
    details = input();
    if(details.size()<2){
        cout << "\nThere must be atleast 2 entries...!";
        return;
    }
    int max_diff = details[1] - details[0];
    int min_num = 0;
    investmentday obj;
    obj.buy_day = 1;
    obj.sell_day = 2;
    for (int i=1;i<details.size();i++){
        if(details[i] - details[min_num] > max_diff){
            max_diff = details[i] - details[min_num];
            obj.buy_day = min_num + 1;
            obj.sell_day = i + 1;
        }
        if(details[min_num] > details[i]){
            min_num = i;
        }
    }
    if(details[obj.buy_day-1] < details[obj.sell_day-1]){
        cout << "\nBuy on day " << obj.buy_day << ", and sell on day " << obj.sell_day << ".";
    }
    else{
        cout << "\nThere is no way to make money...!";
    }

}
