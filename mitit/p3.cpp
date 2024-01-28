#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int MOD = 1e9+7;
vector<int> dr = {0,1,0,-1};
vector<int> dc = {-1,0,1,0};

int main() {    
	int t;
    cin>>t;

    for(;t>0;t--){
        int n,m; // n rows of n chars
        cin>>n>>m;
        vector<string> grid(n);
        for(int j=0;j<n;j++){
            cin>>grid[j];
        }

        long long ans=1;
        
        // brute force sol not accounting for overlaps
        for(int j=0;j<n;j++){
            for(int k=0;k<m;k++){
                if(grid[j][k]=='o'){
                    // check all 4 adj squares for # of possible rotations
                    vector<bool> NESW = {false,false,false,false}; // if north, E, S, W squares work, respectively

                    for(int i=0;i<4;i++){
                        int jj = j+dr[i];
                        int kk = k+dc[i];
                        if(jj>=0 && jj<n && kk>=0 && kk<m && grid[jj][kk]=='.'){
                            NESW[i]=true;
                        }
                    }
                    
                    int numRotations=0;
                    if(NESW[0]){
                        if(NESW[1]) numRotations++;
                    }
                    if(NESW[2]){
                        if(NESW[3]) numRotations++;
                    }
                    if(NESW[3]){
                        if(NESW[0]) numRotations++;
                    }
                    if(NESW[1]){
                        if(NESW[2]) numRotations++;
                    }
                    // cout<<"numRotations: "<<numRotations<<endl;
                    ans*=numRotations;
                    ans%=MOD;

                }
            }
        }

        cout<<ans<<endl;
    }
}