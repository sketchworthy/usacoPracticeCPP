/* Codeforces Educational Div2 Round 93 Problem C: Good Subarrays COMPLETE
https://codeforces.com/contest/1398/problem/C

Idea: Find prefix sum array of OG arr. then create a freq map with 0 already set to 1.
Then, imagine an array that is the values of the prefix sum array minus the indices, 1-indexed.
Then, for each # in this new array, you add 1 to its value when its the key. Then find
the sum of each distinct key's value choose 2.

Difficulty: Ez to find idea with pen and paper, pretty ez to implement. Clarity of mind important for this problem. 
Biggest problem i ran into was debugging, which wasn't working because i used int, then long, instead of
long long :/
*/

#include <iostream> // cout
#include <algorithm> // sort
#include <map> // map

using namespace std;

int main(){
    int t; // # of test cases
    cin >> t;
    for (;t>0;t--){
        long n; // # of #s in subarray
        cin >> n;
        char B[n] = {'0'}; // string of chars
        cin >> B;
        long long A[n] = {0}; // prefix sum array of ints
        long long total=0;
        for(int j=0;j<n;j++){
            total+=B[j]-'0';
            A[j]=total;
        }
        // cout << "\n";
        // for(int j=0;j<n;j++){
        //     cout << A[j];
        // }
        map<long long,long long> freq;
        freq[0]++;
        for(long long j=0;j<n;j++){
            freq[A[j]-j-1]++;
        }

        long long max=0;
        map<long long,long long>::iterator it;
        it=freq.begin();
        while(it!=freq.end()){
            long long x=it->second;
            max+=x*(x-1)/2;
            it++;
            // cout << "\n" << it-> first << ":" << it->second << "\n";
        }
        cout << max;
        if(t!=1)cout << "\n";
    }
}