/*
BB erases the smaller of 2 consec eles
BR erases the larger of 2 consec eles
BB goes 1st: BB wants to maximize # remaining, 
BR wants to minimize # remaining
thus, their respective strats are:
BB always erases the smallest #
BR always erases the largest #
so the last # remaining is the exact middle
# when the elements are sorted
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
    
	int n;
    cin>>n;

    vector<int> A(n);
    for(int j=0;j<n;j++){
        cin>>A[j];
    }

    sort(A.begin(),A.end());

    // if A has an even # of elements (ex: 1,2,3,4)
    if(A.size()%2==0){
        cout<<A[A.size()/2];
    }
    // if A has an odd # of elements (ex: 1,2,3)
	else
        cout<<A[A.size()/2];
    
}