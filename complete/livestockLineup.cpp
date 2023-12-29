/* USACO 2019 Dec Bronze Problem 3  COMPLETE
http://www.usaco.org/index.php?page=viewproblem2&cpid=965

Idea: You can do this problem brute-force by complete basic search, iterating thru all
possible ideas in the solution space. However if the #s were bigger this wouldn't work.
Note that some cows want to be beside each other--connected. When there's 'nodes' that
want/need to be 'connected' I need to think of graphs. Specifically here, adjacency
lists, that then present rules we can follow when building our thing.
If we iterate thru each of the adjacency lists, 

Difficulty: Debugging hella annoying bc i messed up order of 2 lines... hhh...
but otherwise p ez

NOTE: Functions in cpp must be put before the mai method/where they are called(?)
Use bool array to keep track of what's been visited/used
When debugging, use the debugger or go through the code line-by-line when you're fresh
*/

#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

bool contains(int a, vector<int> v){
    // returns true if a in v, else returns false
    for(int x:v){
        if(a==x)return true;
    }
    return false;
}

int main(){
    freopen("lineup.in","r",stdin);
    freopen("lineup.out","w",stdout);

    string cows[] = {"Beatrice", "Belinda", "Bella", "Bessie", "Betsy", "Blue", "Buttercup", "Sue"}; // sorted cow names
    // we will convert referrals to the cows to numbers tho

    // sort(cows, cows+8);

    vector<int> adj[8]; // array of vectors of ints
    // for(int j=0;j<8;j++){
    //     vector<int> v={};
    //     adj[j]=v;
    // }
    
    // read input
    int n; cin>>n; // # of instructions
    for(int j=0;j<n;j++){
        string cow1;
        cin>>cow1;
        string cow2;
        cin>>cow2>>cow2>>cow2>>cow2>>cow2;
        // find the corresponding indices of cow1 and 2
        int a, b;
        for(int i=0;i<8;i++){
            if(cow1.compare(cows[i])==0){
                a=i;
            }
            else if(cow2.compare(cows[i])==0){
                b=i;
            }
        }
        // add the adjacency stuff
        if(!contains(b,adj[a])) 
            adj[a].push_back(b);
        if(!contains(a,adj[b]))
            adj[b].push_back(a);
    }

    // for(int j=0;j<8;j++){
    //     for(int k=0;k<adj[j].size();k++)
    //         cout<<adj[j][k]<<" ";
    //     cout<<endl;
    // }

    // adj list now filled
    bool used[8]={false};
    int checking=0; // checking cow 0
    while(checking<8){ // construct a working lineup
        if(!used[checking]){ // If not in lineup, put checking into lineup
            // check what checking is adjacent to
            if(adj[checking].empty()){
                cout<<cows[checking]<<endl;
                used[checking]=true;
            }
            else if(adj[checking].size()==1){ // 1 neighbor
                cout<<cows[checking]<<endl;
                used[checking]=true;
                // put in checking and all its neighbors
                int c=adj[checking][0]; // current cow ur checking
                cout<<cows[c]<<endl;
                used[c]=true;
                int p=checking; // parent
                int temp=0;
                while(adj[c].size()==2){
                    temp=c;
                    if(adj[c][0]==p){
                        c=adj[c][1];
                    }
                    else{
                        c=adj[c][0];
                    }
                    p=temp;
                    cout<<cows[c]<<endl;
                    used[c]=true;
                }
            }
            // else, if it has 2 neighbors, ignore checking for now.
        }
        checking++;
    }
    // now lineup has been constructed
    // for(int j=0;j<lineup.size();j++){
    //     for(int k=0;k<lineup[j].size();k++){
    //         cout<<cows[lineup[j][k]]<<"\n";
    //     }
    // }
}
