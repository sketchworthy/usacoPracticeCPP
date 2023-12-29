/* Traffic Lights Silver B MomLrn class 9x24x23 hw0301 cpp version NOT COMPLETE
(desc)

Idea: use multiset to keep track of lens. bug rn where stuff is shitty messed up bc indices confusion

Difficulty: */

#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <set> // set in cpp is ordered by default, to get an unordered set u have to type unordered set

using namespace std;

int main(){
    freopen("10.in", "r", stdin);

    int x; // len of passage
    cin >> x;     
    int n; // # of traffic lights
    cin >> n; 

    multiset<int> lights;
    multiset<int> lens;

    long total=0;

    for(;n>0;n--){
        int l;
        cin>>l;
        l--;
        int higher;
        int lower;

        multiset<int>::iterator it = lights.upper_bound(l);
        if(it!=lights.end()){
            higher=*it;
        }
        else{
            higher=x-1;
        }
        // it--; // walk iterator back 1 step
        if(it!=lights.begin()){
            lower=*(--it);
        }
        else{
            lower=0;
        }


        lens.erase(higher-lower);
        lens.insert(higher-l);
        lens.insert(l-lower);
        lights.insert(l);
        total+=*lens.crbegin();
    }
    cout<<total;
}