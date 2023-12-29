/* USACO 2017 Jan Silver Problem 2 COMPLETE
http://www.usaco.org/index.php?page=viewproblem2&cpid=691

Idea: Use prefix sum arrays, then iterate thru each index being the possible change point
and brute force all 6 possible starting stream and ending streams of Hs, Ps, or Ss that Bess
could have chose

difficulty: Once you realize you need to use a prefix sum array, which can be inituitified
by seeing you want to find how many of hoofs, scissors, and papers have appeared before
each index at each point, its ez
*/

#include <iostream>

using namespace std;

int main() {
    freopen("hps.in","r",stdin);
    freopen("hps.out","w",stdout);

    int n;
    cin >> n; // # of games
    char games[n]; // results of games
    int max=0; // max # of games Bess wins
    int P[n]; // prefix sum array for P results of games (P[i] = # of Ps that have occured up to and including current index)
    int H[n];
    int S[n];

    
    P[0]=0;
    H[0]=0;
    S[0]=0;
    for(int j=0;j<n;j++){ // fill games[], P, H, S arrays
        cin >> games[j];
        if(j!=0){
            P[j]=P[j-1];
            H[j]=H[j-1];
            S[j]=S[j-1];
        }
        if(games[j]=='P'){
            P[j]++;
        }
        else if(games[j]=='H'){
            H[j]++;
        }
        else { // S
            S[j]++;
        }
    }

    // for(int j=0;j<n;j++){
    //     cout << P[j] << " ";
    // }
    // cout << "\n";
    // for(int j=0;j<n;j++){
    //     cout << H[j] << " ";
    // }
    // cout << "\n";
    // for(int j=0;j<n;j++){
    //     cout << S[j] << " ";
    // }
    // cout << "\n";

    for(int i=0;i<n;i++){ // current processing index i
        // check sum of subarray 0-i inclusive for A and then sum of subarray i+1 to n-1 inclusive for B for any A,B
        //   aka, check A[i]+B[n-1]-B[i] for any A,B in {P,H; P,S; H,P; ... etc}
        // max=std::max(P[i]+H[n-1]-H[i],max);
        if(P[i]+H[n-1]-H[i]>max) {
            max = P[i]+H[n-1]-H[i];
            // cout << P[i]+H[n-1]-H[i] << "\n";
        }
        if(P[i]+S[n-1]-S[i]>max) max = P[i]+S[n-1]-S[i];
        if(S[i]+H[n-1]-H[i]>max) max = S[i]+H[n-1]-H[i];
        if(S[i]+P[n-1]-P[i]>max) max = S[i]+P[n-1]-P[i];
        if(H[i]+S[n-1]-S[i]>max) max = H[i]+S[n-1]-S[i];
        if(H[i]+P[n-1]-P[i]>max) max = H[i]+P[n-1]-P[i];
    } 

    cout << max;



}