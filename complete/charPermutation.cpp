// idea: permute a list of characters. go in lexographic order, generate the next permutation, then the next.
// https://cses.fi/problemset/task/1622

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

vector<char> str;
int n;
bool chosen[8]={false};
vector<char> permutation;
set<vector<char>> permutes;

void permuteString(){ 
    // idea: recursively compute the next permutation by looping thru the first char being the lexographically 1st, then 2nd, 3rd, etc...
     // then calling function again and only looping thru the unused 
    if(permutation.size()==n){
            permutes.insert(permutation);
        
        return;
    }
    // otherwise loop thru lexographically and call itself
    for(int j=0;j<n;j++){
        if(chosen[j])continue;
        permutation.push_back(str[j]); // add itself
        chosen[j]=true;
        permuteString(); // call itself
        chosen[j]=false; // remove itself
        permutation.pop_back();
    }
    return;
}

int main(){
    string s;
    cin>>s;
    n = s.length();
    for(int j=0;j<n;j++){
        str.push_back(s[j]);
    }
    sort(str.begin(),str.end());
    permuteString();
    cout<<permutes.size();
    for(vector<char> perm:permutes){
        cout<<"\n";
        for(int j=0;j<perm.size();j++){
            cout<<perm[j];
        }
    }
}