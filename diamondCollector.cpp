/* USACO year month Silver COMPLETE
 * http://www.usaco.org/index.php?page=viewproblem2&cpid=643
 * 
 * idea: prefix and suffix max arr. keep a prefix max array
 * of max # of diamonds in any group going backwards and a
 * suffix max arr of max # of diamonds in any group going forwards
 * 
 * difficulty: 
 * 
 * 
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
    
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);
    
	int n; // num of diamonds
    int k; // min # of diff in diamond size in same display case
    cin>>n>>k;
    vector<int> diamonds(n);
    for(int j=0;j<n;j++){
        cin>>diamonds[j];
    }

    sort(begin(diamonds),end(diamonds));

    vector<int> pmx(n); // prefix max arr of max # of diamonds in any group going backwards
    vector<int> smx(n); // suffix max arr of max # of diamonds in any group going forwards

    pmx[0]=1;
    for(int j=1;j<n;j++){
        // binary search for 1st index that will grant 
        auto i = lower_bound(diamonds.begin(),diamonds.end(),diamonds[j]-k);

        pmx[j]=max(pmx[j-1], j-(int)(i-diamonds.begin())+1);
    }

    smx[n-1]=1;
    for(int j=n-2;j>=0;j--){
        // binary search for 1st index that will grant 
        auto i = upper_bound(diamonds.begin(),diamonds.end(),diamonds[j]+k);
        int a1 = (int)(i-diamonds.begin());
        i--;
        int a2 = (int)(i-diamonds.begin());
        int b = (int)(i-diamonds.begin())-j+1;
        smx[j]=max(smx[j+1], (int)(i-diamonds.begin())-j+1);
    }

	int ans = 1;

    for(int j=0;j<n-1;j++){
        ans = max(pmx[j]+smx[j+1],ans);
    }
    
    cout<<ans;
}