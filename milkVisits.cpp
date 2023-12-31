/* USACO 2019 Dec Silver COMPLETE
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
 * what this code does is try to dfs out the cluster based on same-end edges,
 * then check if another node is connected to curr cluster. has some dp elements
 * since i keep track of which nodes are in which clusters
 * 
 * difficulty: implementation seemed actually pretty ez using floodfill, i even came up 
 * w the idea myself. unfortunately my first draft failed all test cases except sample -_-
 * edit: i suspect one of the reasons my code failed all test cases was that i had
 * ints in char form which prob didnt mesh well. one of the big reasons program was
 * failing a lot on time was bc i didnt get visited array to work properly, which
 * i fixed by using cid[] arr. another error was bc i put n instead of m on a for loop :/
 * 
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN=1e5+1;
vector<vector<int>> adj;
char farms[MAXN];
int cid[MAXN]; // cid[x]: cluster ID of node x
int currCid=0;

void dfs(int node){ // fill all of this cluster w dfs
    if(cid[node]==0) cid[node]=currCid;
    else return;
    
    for(int nbor:adj[node]){
        if(cid[nbor]==0 && farms[node]==farms[nbor]){
            dfs(nbor);
        }
    }
}

int main() {
	ios_base::sync_with_stdio(false);
    
    ifstream cin("milkvisits.in");
    ofstream cout("milkvisits.out");
    
    int n,m; // n farms/nodes, m friends/test cases
    cin>>n>>m;
    cin>>farms; // read in string to char arr
    adj.resize(n); // edges linking farms and whether they are true (identical cows at ends) or false
    for(int j=0;j<n-1;j++){
        int a,b; cin>>a>>b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<vector<int>> friends(m, vector<int>(2)); // specifications of friends' starts and ends of routes
    vector<char> prefs(m); // friend's cow preferences
    for(int fren=0;fren<m;fren++){
        int start,end; 
        cin>>start>>end; // start&end of friend journey
        char cow; cin>>cow;

        friends[fren][0]=start-1;;
        friends[fren][1]=end-1;
        prefs[fren]=cow;
    }

    

    for(int j=0;j<m;j++){
        currCid++;
        dfs(friends[j][0]);
        if(farms[friends[j][0]]!=prefs[j] && cid[friends[j][0]]==cid[friends[j][1]]){
            cout<<0;
        }
        else cout<<1;
    }

}