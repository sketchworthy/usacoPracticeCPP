/* Water Jug COMPLETE
 * Given 2 jugs with capacities a and b, a<b, can u make target capacity t?
 * 
 * idea: 
Claim: If the capacities are a and b, you can create any capacity in the range [0,a+b] that is divisible by gcd(a,b)
Let's just prove that we can make any capacity in the range [0,a+b] if a and b are relatively prime.

We just need to prove that you can make any capacity in [0,b], because then we can add that capacity 
onto the a-jug and make any capacity more than b. Note we can make the capacity pair (a,b-a) or (0,b-a), 
where b-a is in the b-jug. We can also make (0,b-2a), (0,b-3a), etc... until (0,b-ka) where k is the 
constant such that b-(k+1)a is negative (so b-ka<a). Given (b-ka,0), we can then make (a, b-(a-(b-ka))) 
= (0, 2b-(k+1)a ). From this we can make (a, 2b-(k+2)a ), (a, 2b-(k+3)a), etc. So we can also make 
2b-(any multiple of a) that fits in jug-b. Can we make 3b-(multiples of a)? Yes! Suppose we have (0,2b-ja) 
for a constant j such that 2b-ja<a. Then we can make (a, b-(a-(2b-ja)) )=(0,3b-(j+1)a ). So it seems that 
from continuing this pattern, we can make any xb-ya as long as 0<xb-ya<b. Since b and a are relatively 
prime, this means we can make all possible numbers! Yay!
 * 
 * difficulty: once u figure it out mathematically the problem is rlly ez to implement.
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
    
	ifstream cin("10.in");

    int ans=0;
    
	int q;
    cin>>q;
    for(;q>0;q--){
        int c1, c2, t;
        cin>>c1>>c2>>t;
        int b = max(c1,c2);
        int a = min(c1,c2);

        int div = gcd(a,b);
        if(t%div==0) ans++;
    }

	cout<<ans;
}