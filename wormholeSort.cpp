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
 * 
 * I ALSO HAD REALLY STUPID DEBUG TROUBLE BC OF 1 TINY THING.
 * i thought that the positions of cows given (3 2 1 4)
 * were the order the cows were currently in but nooo! they
 * meant cow 1 was at pos 3, cow 2 was at pos 2, 3 at 1, etc.
 * READ PROBLEM CAREFULLY.
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> pos; // pos[x] gives cow # at position x
vector<vector<pair<int,int>>> adj; 
// adj[x] has list of pairs containing a position that pos x is connected to and the wormhole's width
vector<vector<int>> wormholes;
int threshold; // wormholes[threshold][2] is smallest wormhole size allowed
// vector<vector<int>> clusters; // info on which POSITIONS are connected. doubles as visited array
vector<int> cid; // cid[x] is cluster id of cow # x
int id; // curr id of cluster

void dfs(int p, int target){
    // find all nodes/positions a cow at position p can reach. if get to target position, stop
    // clusters[id].push_back(pos[p]);
    cid[pos[p]]=id;

    if(p==target) return;

    for(pair<int,int> adjInfo:adj[p]){
        if(cid[pos[adjInfo.first]]!=-1 || adjInfo.second<wormholes[threshold][2])continue;
        dfs(adjInfo.first,target);
    }
}

int main() {
	ios_base::sync_with_stdio(false);
    
	ifstream cin("wormsort.in");
	ofstream cout("wormsort.out");
    
	int n,m; // cows, wormholes
    cin>>n>>m;

    pos.resize(n); // pos[x] gives # cow at position x
    vector<int> idealPos(n); // end goal
    for(int j=0;j<n;j++){ // j is # cow
        int x; cin>>x; x--;
        pos[x]=j;
        idealPos[j]=pos[j];
    }
    sort(idealPos.begin(),idealPos.end());
    if(idealPos==pos){
        cout<<-1;
        return 0;
    }

    wormholes.resize(m,vector<int>(3));
    // wormhole info: edge endpoint position 1, edge endpoint pos 2, width
    for(int j=0;j<m;j++){
        cin>>wormholes[j][0]>>wormholes[j][1]>>wormholes[j][2];
        wormholes[j][0]--; wormholes[j][1]--;
    }

    sort(wormholes.begin(),wormholes.end(), [](vector<int>& a,vector<int>& b){ return a[2]<b[2]; }); 
    // sort wormholes by ascending order of width

    // construct adj graph with all wormhole edges
    adj.resize(n);
    for(int j=0;j<m;j++){ // add each wormhole info
        pair<int,int> adjInfo = {wormholes[j][1],wormholes[j][2]};
        adj[wormholes[j][0]].push_back(adjInfo);
    }
    // clusters.resize(n);
    cid.resize(n);

    int low = 0;
    int high=m-1;

    while(low<high){
        threshold=(low+high+1)/2; // only wormholes w width>=wormholes[threshold][2] allowed
        // evaluate the clusters for each threshold and see if the threshold works

        for(int j=0;j<n;j++) {// clear clusters and cid
            // fill(clusters.begin(),clusters.end(),-1); 
            cid[j]=-1;
        }
        id = -1; // curr cluster id

        bool allWork=true; // bool that describes if all cows can find their desired node
        for(int j=0;j<n;j++){ 
            // for each cow at position j, check if they can reach desired position pos[j] through dfs travel
            id++; // update id

            if(cid[pos[j]]!=-1 && cid[pos[j]]==cid[pos[pos[j]]]){
                continue; // if already know cow can reach position, skip out on dfs
            }
            dfs(j,pos[j]); // cow in position j has id pos[j] and wants to get to index pos[j]. see if possible
            if(cid[pos[pos[j]]]!=id){ // if this cluster hasnt reached desired end
                allWork=false;
                break;
            }
        }
        if(allWork){
            low = threshold;
        }
        else{
            high = threshold-1;
        }
    }
	
    cout<<wormholes[low][2];
}