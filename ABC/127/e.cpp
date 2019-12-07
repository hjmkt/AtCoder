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

ll combi(ll n, ll m, ll mod=1000000007){
    static const ll N_MAX = 200000;
    static vll fac(N_MAX+1, -1);
    static vll ifac(N_MAX+1, -1);

    if(fac[0]<0){
        fac[0] = ifac[0] = 1;
        rep(i, N_MAX){
            fac[i+1] = fac[i] * (i+1) % mod;
            ifac[i+1] = ifac[i] * pow_mod(i+1, mod-2, mod) % mod;
        }
    }

    if(n<=0 && m<=0) return 1;
    if(n<m || n<0) return 0;
    return (ifac[n-m] * ifac[m] % mod) * fac[n] % mod;
}

int main(){
    cout << setprecision(20);
    ll n, m, k;
    cin >> n >> m >> k;

    ll count = 0;
    REP(d, 1, n){
        ll a = d * (n-d) * m * m % 1000000007;
        a = a * combi(n*m-2, k-2) % 1000000007;
        count = (count+a) % 1000000007;
    }
    REP(d, 1, m){
        ll a = d * (m-d) * n * n % 1000000007;
        a = a * combi(n*m-2, k-2) % 1000000007;
        count = (count+a) % 1000000007;
    }

    cout << count << endl;
}

