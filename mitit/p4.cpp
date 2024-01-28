/*
A tree (if n nodes, n-1 edges) is colored with 2 colors, R and G
a connected component of G is 'cool' if 2 or less R nodes are adj to the component
given tree t, f(t) = max # of cool components in a coloring of t

to find f(t) / max # of cool components, 
dfs for all connected components in and of themselves.
then, in each one, dfs for G and count for each G cluster
how many Rs they have adjacent.
WAIT IM SO DUMB--its a tree so the whole graph is 1 connected component.
for a graph to have as many cool components as possible, i've learned
through experimentation that it's ideal to have all leaf nodes for a given root
be single green vertices and adjacent to red nodes on a 1-higher
depth than them. then keep doing the same thing, moving inward on the graph
for the not-yet-visited nodes (EDIT: Problem here, bc the root node may not
be able to be 1 G vertex component bc it has too many red children, or smthn.
but in this case the only way seems to be to make it red and keep going)

for a sub-GConnComponent to have 2 or less R neighbors,



tree t starts with just 1 node, ID 1. there are n queries.
on ith query, leaf node is added by edge to a_i. 


*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;


vector<vector<int>> adj; // adj arr of current tree

int main() {
	ios_base::sync_with_stdio(false);
    
	ifstream cin("x.in");
    
	int t, x; // # of test cases, test type
    // if x=0, f(t) only outputted after all queries done
    // if x=1, f(t) outputted after each query
    cin>>t>>x;

    for(;t>0;t--){
        int n; cin>>n;
        vector<int> A(n); // nodes you add leaves to
        for(int j=0;j<n;j++){
            cin>>A[j];
            A[j]--; // 0-indexed. the og node, node 1, becomes node 0
        }
        
        adj.resize(n+1);
        


    }
}