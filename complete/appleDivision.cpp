/* Apple Division COMPLETE
https://cses.fi/problemset/task/1623/
Given n int weights, split them into 2 subsets so that their sums are as equal as possible, then output the difference

Idea: Save the total sum of all the weights. Generate all the 2^n possible group sums you
could have of the n weights, return the smallest diff between group sums you could have.

Difficulty: Ez once i hit the right idea and got my code right
*/

#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <set>

using namespace std;

set<long long> addSums(long long adder, set<long long> s){
    set<long long> s2;
    for(long long ele:s){
        s2.insert(ele);
        s2.insert(ele+adder);
    }
    return s2;
}

int main(){
    int n; cin>>n; // # of weights
    long long nums[n];
    long long sum=0;
    for(int j=0;j<n;j++){ // input in weights
        cin>>nums[j];
        sum+=nums[j];
    }
    set<long long> s = {0};
    for(int j=0;j<n;j++){
        s=addSums(nums[j],s);
    }
    
    long long minDiff=abs(sum-nums[0]*2);
    for(long long o:s){
        minDiff=min(abs(sum-o*2),minDiff);
    
    }
    cout<<minDiff;
}