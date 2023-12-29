// For each person x, report the person y who has the minimum 
// quiet value among all people with money at least the same 
// as person x.

// plan: dfs each person, keeping a running tally of who is the max value. 
//  add dp easily by keeping an ans[] array to cut out redundant work

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<int>> adj;
vector<int> quiet;
vector<int> ans;

int dfs(int node){ 
	// node is current node, return person with min quiet value 
	// among all children of node according to adj
	if(adj[node].size()==0){
        ans[node] = node;
        return node;
    }
    if(ans[node]!=-1){
        return ans[node];
    }

	int min=node;
	for(int child:adj[node]){
        int assessing = dfs(child);
		if(quiet[assessing]<quiet[min]){
			min=assessing;
		}
	}
    ans[node]=min;
	return min;
}

int main() {
	int n, m; cin >> n >> m; // n nodes m edges
	adj.resize(n); // ppl in adj[k] have more money than k
	quiet.resize(n); // quietness values of everyone
    ans.resize(n,-1);
	for(int j=0;j<n;j++) cin>>quiet[j];
	for(int j=0;j<m;j++){
		int a,b; cin>>a>>b;
		// adj[a].push_back(b);
		adj[b].push_back(a); 
	}

	for(int j=0;j<n;j++){
		cout<<dfs(j)<<endl;
	}
}