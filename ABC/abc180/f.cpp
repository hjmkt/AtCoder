#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;
using vvvvll = vector<vvvll>;

#define REP(i, n, m) for(ll i=n; i<(ll)m; ++i)
#define IREP(i, n, m) for(ll i=n-1; i>=m; --i)
#define rep(i, n) REP(i, 0, n)
#define irep(i, n) IREP(i, n, 0)
#define all(v) v.begin(), v.end()
#define vprint(v) for(auto e:v){cout<<e<<" ";};cout<<endl;
#define vvprint(vv) for(auto v:vv){vprint(v)};

ll pow_mod(ll n, ll m, ll mod=1000000007){
    ll a = 1;
    while(m>0){
        if(m&1) a = a*n % mod;
        n = n*n % mod;
        m >>= 1;
    }
    return a;
}

ll perm(ll n, ll m, ll mod=1000000007){
    static const ll N_MAX = 200001;
    static vll fac(N_MAX+1, -1);
    static vll ifac(N_MAX+1, -1);
    if(fac[0]<0){
        fac[0] = ifac[0] = 1;
        rep(i, N_MAX){
            fac[i+1] = fac[i] * (i+1) % mod;
            ifac[i+1] = ifac[i] * pow_mod(i+1, mod-2, mod) % mod;
        }
    }
    return (fac[n]*ifac[m]) % mod;
}

ll combi(ll n, ll m, ll mod=1000000007){
    static const ll N_MAX = 200001;
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
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);

    ll N, M, L;
    cin >> N >> M >> L;

    vvvvll dp(N+1, vvvll(M+1, vvll(L+1, vll())));
    rep(n, N+1) rep(m, M+1) REP(l, L+1, 1) rep(c, n/l){
        if(n==0){
            dp[n][m][l].push_back(1);
            continue;
        }
        if(m<(l-1)*c){
            dp[n][m][l].push_back(0);
            continue;
        }
        ll count = 0;
        REP(e, (l-1)*c, min(l*c+1, m)){
            ll d = l*c - e;
            ll p = combi(c, d);
            count = (count + p*dp[n-l*c][m-e][l-1]) % 1000000007;
        }

        ll t = combi(n, l*c) * perm(l*c, l) % 1000000007;
        t = (t * dp[n-l*c]) % 1000000007;
    }

    ll ans = 0;
    for(ll a : dp[N][M][L]) ans = (ans+a) % 1000000007;
    cout << ans << endl;
}
