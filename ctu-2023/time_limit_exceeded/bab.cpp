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

ll besticando2(ll last, vll & v){
    ll sum = 0;
    fr(i, v.size()){
        ll best = 0;
        fr(j,i){
            if(i != j){
                best = max(best, __gcd(v[i], v[j]));
            }
        }
        best = max(best, __gcd(v[i], last));
        sum += best;
    }
    return sum;
}

ll besticando(ll last, vll & v){
    ll sum = 0;
    ll m = last;
    fr(i, v.size()){
        sum += v[i];
        m = min(v[i], m);
    }
    return sum - m;
}

ll bestsofar = 0;
ll lb = 0;
ll bf(vll & v, ll sofar, ll last){
    if(v.size() == 0){
        bestsofar = max(bestsofar, sofar);
    }
    if(sofar + besticando(last, v) < bestsofar){
        return -1;
    }
    fr(i, v.size()){
        ll a = v[i];
        v[i] = v[v.size()-1];
        v.pop_back();
        bf(v, sofar + __gcd(last, a), a);
        v.push_back(v[i]);
        v[i] = a;
    }
    return bestsofar;
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
    cost += bf(v, 0, 1) -1;
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
