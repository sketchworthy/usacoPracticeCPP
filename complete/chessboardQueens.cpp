// COMPLETE
// idea: recursively place a queen on the earliest spot possible and iterate thru
// EDIT: I need to FIRST think not of fancy algorithms but instead just. plain logic. bc i missed
//  the obvious first step of reducing the problem to just looking at a queen in each row and col
/*
First, note that the queen locs can be described as the 8! permutations of {0,1,2...7} where
the first index's value describes the location of the queen in the 1st row. For each permutation
we then test if it works against the reserved places on the board. if it does, ans++.
ALSO EDIT: IM STUPID. READ THE PROBLEM CAREFULLY, UR SUPPOSED TO USE QUEENS NOT ROOKS!!!!
*/
// https://cses.fi/problemset/task/1624
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int n=8;

int main(){
    char board[n][n];
    int total=0;

    for(int j=0;j<n;j++){
        cin>>board[j];
    }
    
    vector<int> queenLocs = {0,1,2,3,4,5,6,7}; // manually adjust 
    do{
        bool works=true;
        for(int j=0;j<n;j++){ // for queen of row j
            int i=queenLocs[j];
            if(board[j][i]=='*'){ // checks row, col, and reserved
                works=false;
                break;
            }
            // check that diagonals dont interfere
            for(int k=0;k<n;k++){ // row of possible no-queen spaces determined by the queen of row j
                if(k==j)continue; // if same row
                // if(k==i)continue; // if same col
                if(abs(k-j)==abs(queenLocs[k]-i)){
                    works=false;
                    break;
                }
            }
        }

        if(works) total++;
    }
    while (next_permutation(queenLocs.begin(),queenLocs.end()));

    cout<<total;
}