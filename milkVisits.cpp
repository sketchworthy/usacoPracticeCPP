/* USACO 2019 Dec Silver COMPLETE???
 * http://www.usaco.org/index.php?page=viewproblem2&cpid=968
 * 
 * idea: solve using floodfill.
 * each edge is either tru or false. tru if both endnodes have identical cows,
 * false if endnodes have opposite cows. in order for a friend to be unhappy, they would
 * have to only traverse edges that are true and one of the nodes is the milk type they
 * DON'T like. since path is a tree, there is only 1 way to get from each node to another.
 * floodfill all clusters connected by solely G-G endpoints and solely H-H endpoints,
 * keeping track of cluster id of each node as u go.
 * then at the end we can just see if cluster ids match.
 * 
 * difficulty: implementation seemed actually pretty ez using floodfill, i even came up 
 * w the idea myself. unfortunately my first draft failed all test cases except sample -_-
 * 
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
	ios_base::sync_with_stdio(false);
    
    freopen("milkvisits.in", "r", stdin);
    freopen("milkvisits.out", "w", stdout);
    
    int n,m; // n farms/nodes, m friends/test cases
    cin>>n>>m;

    char farms[n]; // identities of cows on farms
    cin>>farms; // read in string to char arr

    vector<vector<int>> adj(n); // edges linking farms and whether they are true (identical cows at ends) or false
    for(int j=0;j<n-1;j++){
        int a,b; cin>>a>>b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<vector<char>> friends(m, vector<char>(3)); // specifications of friends' preferences
    for(int fren=0;fren<m;fren++){
        int start,end; 
        cin>>start>>end; // start&end of friend journey
        char cow; cin>>cow;

        friends[fren][0]=start-1;;
        friends[fren][1]=end-1;
        friends[fren][2]=cow;
    }

    vector<int> gcid(n,-1); // gcluster id of each node
    vector<int> hcid(n,-1); // hcluster id of each node
    // floodfill to find gclusters and hclusters separately
        // floodfill gclusters
    int ci = 0; // current new cluster index
    for(int j=0;j<n;j++){
        if(farms[j]=='G' && gcid[j]!=-1) continue;

        gcid[j]=ci;
        queue<int> q; // queue of curr nodes in cluster
        q.push(j);
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int nbor:adj[node]){
                if(farms[nbor]=='G' && gcid[nbor]==-1) {
                    gcid[nbor]=ci;
                    q.push(nbor);
                }
            }
        }

        ci++;
    }

        // floodfill hclusters
    ci = 0; // current new cluster index
    for(int j=0;j<n;j++){
        if(farms[j]=='H' && hcid[j]!=-1) continue;

        hcid[j]=ci;
        queue<int> q; // queue of curr nodes in cluster
        q.push(j);
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int nbor:adj[node]){
                if(farms[nbor]=='H' && hcid[nbor]==-1) {
                    hcid[nbor]=ci;
                    q.push(nbor);
                }
            }
        }

        ci++;
    }

    for(int j=0;j<n;j++){
        char wantedCow = friends[j][2];
        if(wantedCow=='G'){ 
            // check to make sure start and end of this friend arent in the same H cluster
            if(hcid[friends[j][0]]==hcid[friends[j][1]] && hcid[friends[j][0]]!=-1){
                cout<<0;
            }
            else cout<<1;
        }
        else{
            // check to make sure start and end of this friend arent in the same G cluster
            if(gcid[friends[j][0]]==gcid[friends[j][1]] && gcid[friends[j][0]]!=-1){
                cout<<0;
            }
            else cout<<1;
        }
    }

}