/* Moo Particle Silver B MomLrn class 9x17x23 hw0202 cpp version COMPLETE
(desc)

Idea: process particles in sorted order with stack

Difficulty: */

#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <set> // set in cpp is ordered by default, to get an unordered set u have to type unordered set

using namespace std;

int main(){
    freopen("moop.in", "r", stdin);
    freopen("moop.out", "w", stdout);

    int n; // # of particles
    cin >> n; 
    vector<vector<int>> pts(n, vector<int>(2,0));
    for(int j=0;j<n;j++){
        cin>>pts[j][0];
        cin>>pts[j][1];
    }
    sort(pts.begin(),pts.end(),[](vector<int> &a, vector<int> &b){ // sort 1st by ascending order left to right, then by bottom to top
        if(a[0]==b[0])return a[1]<b[1];
        return a[0]<b[0];
    });

    stack<int> s; // takes in stack of y-values of still existing points that have been processed

    for(int j=0;j<n;j++){ // loop thru points
        if(!s.empty()) {
            int mn = s.top();
            while(!s.empty()){
                if(s.top()>pts[j][1]){ // found stopping point
                    break;
                }
                // otherwise remove and try again
                s.pop();
            }
            if(mn<pts[j][1])s.push(mn);
            else s.push(pts[j][1]);
        }
        else s.push(pts[j][1]);
    }

    cout<<s.size();
}