#include <bits/stdc++.h>

using namespace std;

using ll = long long int;
using ld = long double;
using vll = vector<ll>;

#define fr(i, x) for(ll i = 0; i < ll(x); ++i)

ll cost(const vll & v){
    ll s = 0;
    fr(i, v.size()-1){
        s += __gcd(v[i], v[i+1]);
    }
    return s;
}

ll bf(vll v){
    ll maxcost = 0;
    while(next_permutation(v.begin(), v.end())){
        maxcost = max(maxcost, cost(v));
    }
    return maxcost;
}

void solve(){
    ll n;
    cin >>n;
    ll cost = 0, mask =0;
    fr(i, n){
        ll a;
        cin >> a;
        if((mask | (1 << a)) == mask ){
            cost +=a;
        } else{
            mask = mask | (1 << a);
        }
    }
    vector<ll> v;
    set<ll> forbidden = {1,11,13,17,19};
    for(int i = 1; i <= 20;++i){
        if((mask | (1 << i)) == mask){
            if(forbidden.count(i)){
                cost +=1;
            } else{
                v.push_back(i);
            }
        }
    }
    cost += bf(v);
    if(v.size() == 0){
        cost -= 1;
    }
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
