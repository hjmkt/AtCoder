#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;

#define REP(i, n, m) for(ll i=n; i<(ll)m; ++i)
#define IREP(i, n, m) for(ll i=n-1; i>=m; --i)
#define rep(i, n) REP(i, 0, n)
#define irep(i, n) IREP(i, n, 0)
#define all(v) v.begin(), v.end()


ll pow_mod(ll n, ll m, ll mod=1000000007){
    ll a = 1;
    while(m>0){
        if(m&1) a = a*n % mod;
        n = n*n % mod;
        m >>= 1;
    }
    return a;
}


int main(){
    cout << setprecision(20);

    ll N, K;
    cin >> N >> K;

    vll a(K+1, 0);
    IREP(i, K+1, 1){
        ll n = pow_mod(K/i, N);
        for(ll m=2*i; m<=K; m+=i) n -= a[m];
        a[i] = n;
    }

    ll total = 0;
    REP(i, 1, K+1) total = (total+i*a[i]) % 1000000007;
    cout << total << endl;
}
