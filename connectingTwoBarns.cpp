/* USACO 2021 December Silver 1 TEST CASE NOT WORKING
 * http://www.usaco.org/index.php?page=viewproblem2&cpid=1159
 * 
 * idea: set up adjacency list and detect all clusters. then find the min of
 * the dist between the cluster containing 1 and the cluster containing n,
 * as well as 2 other cases
 * 
 * difficulty: REMEMBER TO ADD A & TO FUCTION PARAMETER SO IT'S PASS BY REFERENCE
 * Also i had trouble with debugging because of unclear variable names and
 * lack of comments, so CLARITY IS IMPORTANT
 * 
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int dist(vector<int>& c1, vector<int>& c2){ // CURRENTLY THERE IS 1 TEST CASE FAILING BC THERE'S
// SOMETHING WRONG W THIS METHOD. REPLACING W BINARY SEARCH MAKES IT WORK
    // given clusters c1 and c2, find min dist. return -1 if unmakeable in 2 steps
    int ci = 0; // current smallest index s.t. clusters[ci2][ci]>= clusters[ci1]'s current node
    int minAns=1e9;
    for(int currNode:c1){
        while(ci<c2.size()-1 && c2[ci+1]<currNode){
            ci++;
        }
        minAns = min(minAns,abs(c2[ci]-currNode));
        if(ci>0){
            minAns = min(minAns,abs(c2[ci-1]-currNode));
        }
    }
    return minAns;
}

int main() {
    int t; cin>>t;
    for(;t>0;t--){
        int n; // # of nodes
        int m; // # of edges
        cin>>n>>m;

        // create adj
        vector<vector<int>> adj(n);
        for(int j=0;j<m;j++){
            int a,b; cin>>a>>b;
            a--; b--;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        vector<vector<int>> clusters(n);
        // vector<int> cID(n,-1); // cID[x] gives index of cluster
        int cID[n]; fill(cID, cID+n,-1);
        int ci=-1; // current cluster index

        // detect clusters
        for(int j=0;j<n;j++){ // for every cluster, check if its part of a new cluster
            if(cID[j]!=-1) continue; // if already part of cluster, skip
            ci++;
            cID[j]=ci;
            clusters[ci].push_back(j);

            // add all neighbors to clusters[ci]
            int currI = 0;
            while(currI<clusters[ci].size()){
                int currNode = clusters[ci][currI];

                for(int nbor:adj[currNode]){ // add every neighbor of every node in clusters[ci] to it
                    if(cID[nbor]==-1){
                        cID[nbor]=ci;
                        clusters[ci].push_back(nbor);
                    }
                }
                currI++;
            }
            sort(begin(clusters[ci]),end(clusters[ci])); // sort each cluster, for later
        }

        int c1 = cID[0];
        int c2 = cID[n-1];

        // case 1
        ll y = dist(clusters[c1],clusters[c2]);
        ll ans = y*y;


        // case 2 & 0
        for(int w=0;w<=ci;w++){ // for every possible cluster #
            if(w==c1 || w==c2) continue;
            ll a = dist(clusters[w],clusters[c1]); // for some reason doing dist(clusters[c1],clusters[w]) takes a LOT more time
            ll b = dist(clusters[w],clusters[c2]);
            ans = min(ans,a*a + b*b);
        }

        cout << ans << '\n';
    }
}