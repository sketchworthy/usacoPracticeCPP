/* Max # of events Silver B MomLrn class 9x17x23 hw0201 cpp version NOT COMPLETE
(desc)

Idea:

Difficulty: */

#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <set> // set in cpp is ordered by default, to get an unordered set u have to type unordered set

using namespace std;

int main(){
    int n; // # of events
    cin>>n;
    vector<vector<int>> events(n,vector<int>(2,0)); // start and end times of events.
    // 2d vector w n rows and 2 cols all prefilled w 0s

    // for(int j=0;j<events.size();j++){ // print debug check
    //     for(int k=0;k<events[j].size();k++){
    //     cout<<events[j][k]<<" ";
    //     }
    //     cout<<endl;
    // }

    for(int j=0;j<n;j++){
        cin>>events[j][0];
        cin>>events[j][1];
    }

    // sort by start time and then by end time
    sort(events.begin(),events.end(),[](vector<int>&a,vector<int>&b){if(a[0]==b[0])return a[1]<b[1]; else return a[0]<b[0];}); 
    
}