/* USACO 2016 Dec Silver COMPLETE
http://www.usaco.org/index.php?page=viewproblem2&cpid=666

Idea: 

Difficulty: */

#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <set> // set in cpp is ordered by default, to get an unordered set u have to type unordered set

using namespace std;

int main(){
    // freopen("haybales.in","r",stdin);
    // freopen("haybales.out","w",stdout);
    
    int n; // # of points
    cin>>n;
    int q; // # of queries
    cin>>q;

    vector<int> points(n+2,0);
    for(int j=0;j<n;j++){
        int x;
        cin>>x;
        points.push_back(0);
        points.push_back(x);
    }
    points.push_back(1e9+1);
    sort(points.begin(),points.end());

    for(;q>0;q--){
        int s; int e;
        cin>>s; cin>>e;
        
        vector<int>::iterator itj = lower_bound(points.begin(),points.end(),s);
        vector<int>::iterator itk = upper_bound(points.begin(),points.end(),e);
        
        itk--;
        if(*itj==1e9+1)cout<<0<<endl;
        else {
            cout<<(*itk-*itj+1)<<endl;
        }
    }

}