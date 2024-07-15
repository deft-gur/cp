#include <bits/stdc++.h>

using namespace std;

using ll = long long int;
using ld = long double;
using vll = vector<ll>;

#define fr(i, x) for(ll i = 0; i < (x); ++i)

ll DP[20][(1<<20)];
ll rec(int mask, int c){
    if(mask == 0){
        return 0;
    } else if(DP[c-1][mask] != 0){
        return DP[c-1][mask];
    }
    ll maxcost = 0;
    for(int i = 0; i < 20; ++i){
        if(((1 << i) | mask) == mask){
            ll tmpcost = __gcd(i+1, c) + rec(mask - (1<<i), i+1);
            maxcost = max(maxcost, tmpcost);
        }
    }
    return DP[c-1][mask] = maxcost;
}

void solve(){
    ll n;
    cin >>n;
    ll cost = 0, mask =0;
    fr(i, n){
        ll a;
        cin >> a;
        if((mask | (1 << (a-1))) == mask ){
            cost +=a;
        } else{
            mask = mask | (1 << (a-1));
        }
    }
    cost += rec(mask, 1) - 1;
    cout << cost << endl;
}

int main(void){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	cout<<setprecision(9)<<fixed;
	ll t = 1;
	// cin >> t;
	fr(i, t){
		solve();
	}
	return 0;	
}
