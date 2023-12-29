/* Towers Silver B MomLrn class 9x23x23 ex0302 cpp version COMPLETE
(desc)

Idea: learn to use multisets for dynamic sorting cpp

Difficulty: */

#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; // # of cubes
    cin>>n;
    multiset<int> tops; // top of towers
    for(int i=0;i<n;i++){
        int c; // side length of new cube
        cin>>c;
        if(!tops.empty()){
            multiset<int>::iterator it = tops.upper_bound(c); // returns iterator to first element greater than c

            if(it!=tops.end()){ // if we find an element that is upper bound in ms
                tops.erase(it); // remove the value iterator is pointing to from multiset
            }
        }
        tops.insert(c);
    }
    cout<<tops.size();
}