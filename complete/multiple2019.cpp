/* Multiple of 2019 COMPLETE
https://atcoder.jp/contests/abc164/tasks/abc164_d
"Given a string of ints, return the substrings that turn out to be multiples of 2019."

Idea: Use a mod 2019 suffix array. If a substring is divisible by 2019, and it
starts with index i and ends w index j, then the sufarr vals of i and j should
be the same.

Difficulty: Pen and paper, think about the problem and how to solve it, first.
Then, and only THEN, implementation.


WARNING: str[x] gives the ascii char val, not the numerical val!
*/
#include <iostream> // cin&cout
#include <vector> // vector
#include <algorithm> // sort
#include <map>// map

using namespace std;

#define MOD 2019

int main(){
    string str; // basically an array already
    cin >> str;
    long long n=str.length();
    // create mod 2019 table of pows of 10
    long long pow10mods[n];
    long long product=1;
    for(int j=0;j<n;j++){
        product*=10;
        product%=MOD;
        pow10mods[j]=product;
    } // this took time O(n)


    long long suffS[n]={0}; // suffix mod 2019 array of S
    product=str[n-1]-'0'; // WARNING: str[x] gives the ascii char val, not the numerical val!

    suffS[n-1]=product;
    int p=0;
    for(int j=n-2;j>=0;j--){
        product+=(str[j]-'0')*pow10mods[p]; p++;
        product%=MOD;
        suffS[j]=product;
    } // this took time O(n)

    // for(int j=0;j<n;j++){
    //     cout<<" "<<suffS[j];
    // }
    // cout << "\n";

    map<long long,long long> freq;
        freq[0]++;
        for(long long j=0;j<n;j++){
            freq[suffS[j]]++;
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

}

// TODO learn from other ppl's solutions how to do cin>>S[] here when the str has already been put into a string variable