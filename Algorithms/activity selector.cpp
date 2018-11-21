/*
Implementation of iterative activity selection problem
Written by : Smrity Chaudhary
Dated      : 21/11/2018
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<set>
using namespace std;

vector< pair<int,int> > input();
void activity_selector();
int main() {
    /*
    Objective       : Driver function of the program.
    Input Parameter : None
    Output Value    : None
    */
    activity_selector();
}

vector< pair<int,int> > input() {
    /*
    Objective       : To take Input from user.
    Input Parameter : None
    Return value    : List of activity's start and finish time
    Description     : To store the start and finish time of an activity a vector
                        stores a pair type with two integer values having start
                        and finish time of activity.
    */
    vector< pair<int,int> > activity_time;
    int number_of_activities;
    cout << "Enter number of activities: ";
    cin >> number_of_activities;
    pair<int,int> time;
    while (number_of_activities != 0){
            cout << "\n\nEnter start time of activity: ";
            cin >> time.second;
            cout << "Enter end time of activity: ";
            cin >> time.first;
            activity_time.push_back(time);
            number_of_activities--;
    }
    return activity_time;
}

void activity_selector() {
    /*
    Objective       : To select the maximum size subset of mutually compatible
                        activities.
    Input parameter : None
    Output value    : Maximum size subset of mutually compatible activities.
    Description     : Activities will be sorted with respect to the finish time.
                        Then find next activity with start time more than finish
                        time of previous activity, update the activity subset.
    */
    vector< pair<int,int> > activity_time;
    activity_time = input();
    sort(activity_time.begin(),activity_time.end() );
    set< pair<int,int> > activity_subset;
    int k = 0;
    activity_subset.insert(activity_time[0]);
    for (int i=2;i<activity_time.size();i++){
        if(activity_time[i].second >= activity_time[k].first) {
            activity_subset.insert(activity_time[i]);
            k = i;
        }
    }
    //Print the maximum size subset of mutually compatible activities.
    set< pair<int,int> >::iterator iter;
    cout << "\n\n**Maximum subset of compatible activities**\n\n ";
    pair<int,int> time;
    for(iter = activity_subset.begin();iter!=activity_subset.end();iter++) {
        time = *iter ;
        cout << "\nActivity :\n" << "\tstart time: " << time.second
        << "\n\tfinish time: " << time.first;
    }
}
