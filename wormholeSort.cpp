/* USACO 2020 Jan Silver COMPLETE???
 * http://www.usaco.org/index.php?page=viewproblem2&cpid=992
 * given n cows that want to swap with each other to get to
 * their proper positions thru given edges, find the largest
 * smallest edge that will allow all cows to get to where
 * they gotta be
 * 
 * idea: inverse binary search. we find the wormhole width 
 * threshold that way, then see if the allowed edges there 
 * give all cows the ability to make it to the position
 * they need to reach. we also must prove that if there exists
 * a way for all cows to make it to their desired end, then
 * just swaps will be sufficient to place everyone in ends.
 * edit: thru paper trial and error im p sure its true.
 * 
 * difficulty: i hit a roadbump and was stumped for a while on
 * how to address the 1e9 wormhole edges, which meant if i
 * reconstructed the graph for every inverse binary search
 * attempt would take WAY too long, but then i realized
 * this is a problem where i can use dfs to just go down the
 * paths open to me (like with millionaire madness, that duck
 * grid problem, where the ladder length dictates what edges
 * are available)
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<pair<int,int>>> adj; 
// adj[x] has list of pairs containing a node x is adjacent to and the wormhole's width
vector<vector<int>> wormholes;
int threshold; // smallest wormhole size allowed
vector<bool> visited;

void dfs(int node, int target){
    // find all nodes this node can reach, if found target, stop
    visited[node]=true;
    if(node==target) return;

    for(pair<int,int> adjInfo:adj[node]){
        if(visited[adjInfo.first] || adjInfo.second<threshold)continue;
        dfs(adjInfo.first,target);
    }
}

int main() {
	ios_base::sync_with_stdio(false);
    
	// ifstream cin("wormsort.in");
	// ofstream cout("wormsort.out");
    
	int n,m; // cows, wormholes
    cin>>n>>m;

    vector<int> pos(n); // positions of n cows;
    vector<int> idealPos(n); // end goal
    for(int j=0;j<n;j++){
        cin>>pos[j]; pos[j]--;
        idealPos[j]=pos[j];
    }
    sort(idealPos.begin(),idealPos.end());
    if(idealPos==pos){
        cout<<-1;
        return 0;
    }

    wormholes.resize(m,vector<int>(3));
    // wormhole info: edge endpoint 1, edge endpoint 2, width
    for(int j=0;j<m;j++){
        cin>>wormholes[j][0]>>wormholes[j][1]>>wormholes[j][2];
        wormholes[j][0]--; wormholes[j][1]--; wormholes[j][2]--;
    }

    sort(wormholes.begin(),wormholes.end(), [](vector<int>& a,vector<int>& b){ return a[2]<b[2]; }); 
    // sort wormholes by ascending order of width

    // construct adj graph with all wormhole edges
    adj.resize(n);
    for(int j=0;j<m;j++){ // add each wormhole info
        pair<int,int> adjInfo = {wormholes[j][1],wormholes[j][2]};
        adj[wormholes[j][0]].push_back(adjInfo);
    }
    visited.resize(n);

    int low = 0;
    int high=m-1;

    while(low<high){
        threshold=(low+high+1)/2; // only wormholes w width>=wormholes[threshold][2] allowed

        visited = {false};
        bool allWork=true;
        for(int j=0;j<n;j++){ 
            // for each cow pos[j], check if they can reach position j through dfs travel
            if(!visited[j]){
                allWork=false;
                break;
            }
            dfs(pos[j],j);
        }
        if(allWork){
            high = threshold;
        }
        else{
            low = threshold+1;
        }
    }
	
    cout<<wormholes[low][2];
}