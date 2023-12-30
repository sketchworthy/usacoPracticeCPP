/* Max length string concatenation COMPLETE
 * Given an array of strings A, report the max possible length of
    a concatenation of A's elements such that the concatenation
    has all unique characters.
 * 
 * idea: dfs. for the adj array, have every word be adjacent to all 
 * the words after it. then in order to construct a word, just dfs
 * over all possible threads of word concatenation. to keep a separate
 * track of words for every dfs call, use strings and concatenate them
 * so its a copy and not just a shallow copy. this only works bc
 * the max num of strings is so small (16 max).
 * 
 * difficulty: i took a while to figure out implementation details,
 * esp the trick to use strings to keep deep copies for every dfs call
 * 
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int ans; // max length
vector<vector<int>> adj; // word indices are nodes
vector<string> A; // list of strings

bool isUnique(string s){
    bool freq[26] = {false};
    for(char c:s){
        if(freq[c-'a']) return false;
        freq[c-'a']=true;
    }
    return true;
}

void dfs(int node, string s){
	s+=A[node];
    if(!isUnique(s)) return;
    ans = max(ans, (int)s.length());


    for(int nextWordI:adj[node]){
        dfs(nextWordI, s);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
    
	// ifstream cin("x.in");
    
	int n;
    cin>>n;
    A.resize(n);
	for(int j=0;j<n;j++){
		cin>>A[j];
	}

	adj.resize(n);
	for(int j=0;j<n;j++){
		for(int k=j+1;k<n;k++){
			adj[j].push_back(k); // each jth word can connect to any word after it
		}
	}

	ans = 0;

	for(int j=0;j<n;j++){
		dfs(j,"");
	}

	cout<<ans;
}