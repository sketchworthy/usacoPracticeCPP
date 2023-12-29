/* USACO 2020 Mar Silver COMPLETE
http://usaco.org/index.php?page=viewproblem2&cpid=1038
Silver B HW0402 Momentum Learning

Idea: inverse binary search

Difficulty: had debug trouble bc i accidentally set long long last = 0
instead of long long last = ends[0][0]. be careful about what i initalize variables to!!! */

#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <map>
#include <vector> // constructor parentheses for a vector are # of total elements, what each ele should be
#include <set> // set in cpp is ordered by default, to get an unordered set u have to type unordered set

using namespace std;

int main(){
    freopen("socdist.in", "r", stdin);
    freopen("socdist.out", "w", stdout);

    int n, m; // # of cows, # of intervals
    cin>>n>>m;
    vector<vector<long long>> ends(m, vector<long long>(2,0) ); // 2d vector
    for(int j=0;j<m;j++){
        cin>>ends[j][0]>>ends[j][1];
    }

    sort(ends.begin(),ends.end(), [](vector<long long> &a, vector<long long> &b) { return a[0]<b[0]; } ); // lambda expression sort

    // inverse binary search for D, the max # of units cows are apart
    long long low=1;
    long long high=1e18+1;
    while(low<high){
        long long mid = (low+high+1)/2; // check if mid as the min dist between cows works
        long long last = ends[0][0]; // last loc where a cow was placed
        long long num=1; // # of cows alr placed
        for(int c=0;c<m;c++){ // c is index of current interval we are placing cows in
            long long span = ends[c][1]-max(last+mid,ends[c][0]);
            if(span>=0) {
                num++;
                last=max(last+mid,ends[c][0]);
                num+=span/mid;
                last=last+(span/mid)*mid;
            }
        }

        if(num>=n){ // if worked, d is small enough
            low=mid;
        }
        else{ // if d needs to be smaller
            high=mid-1;
        }
    }
    cout<<high;
}