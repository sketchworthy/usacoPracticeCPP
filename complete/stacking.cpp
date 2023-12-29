/* USACO 2012 Jan Bronze Problem 2 COMPLETE
http://www.usaco.org/index.php?page=viewproblem2&cpid=691

Idea: Use prefix diff arrays to efficiently record the stack commands. then,
rebuild the sequence of haybales after the stackings using the
prefix diff array. then, sort the new sequence and return the contents of
the middle element.

Difficulty: Hard part is realizing you have to use prefix diff arrays, which I will know to 
use in the future when I encounter sections that will be added to and need to
know all elements values
*/

#include <iostream> // cout
#include <algorithm> // sort

using namespace std;

int main(){
    // freopen("stacking.in", "r", stdin);
    // freopen("stacking.out", "w", stdout);

    int n, k;
    cin >> n; // # of haybale stacks
    cin >> k; // # of instructions

    int stacksDiff[n] = {0}; // prefix diff arr
    // for(int j=0;j<n;j++){
    //     cout << stacksDiff[j] << " ";
    // }

    for(int j=0;j<k;j++){ // read in instructions
        int a, b;
        cin >> a;
        cin >> b;
        a--; b--; // adjust bc a,b were 1-indexed
        // cout << a << "           ";
        // cout << b << "                                    "; 
        stacksDiff[a]++;
        if(b<n-1) stacksDiff[b+1]--;   
        // for(int j=0;j<n;j++){
        //     cout << stacksDiff[j] << " ";
        // }
    }

    int stacks[n]; // # of haybales in stacks
    stacks[0]=stacksDiff[0];
    for(int j=1;j<n;j++){    // calculate og array
        stacks[j]=stacks[j-1]+stacksDiff[j];
    }

    // sort stacks[]
    sort(stacks,stacks+n); // how to sort an array cpp


    // for(int j=0;j<n;j++){
    //     cout << stacksDiff[j] << " ";
    // }

    // print out middle element
    cout << stacks[n/2];


}