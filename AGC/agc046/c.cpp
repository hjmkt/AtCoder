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
#define vprint(v) for(auto e:v){cout<<e<<" ";};cout<<endl;
#define vvprint(vv) for(auto v:vv){vprint(v)};


ll pow_mod(ll n, ll m, ll mod=998244353){
    ll a = 1;
    while(m>0){
        if(m&1) a = a*n % mod;
        n = n*n % mod;
        m >>= 1;
    }
    return a;
}


ll combi(ll n, ll m, ll mod=998244353){
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

    string S;
    cin >> S;
    ll K;
    cin >> K;

    K = min(K, (ll)S.length());

    ll c1 = 0;
    vll t;
    rep(i, S.length()){
        if(S[i]=='1') ++c1;
        else{
            t.push_back(c1);
            c1 = 0;
        }
    }
    t.push_back(c1);

    ll n = t.size();
    vvll dp(n, vll(K+1, 0));
    dp[0][0] = 1;
    REP(i, 1, n) rep(j, K+1){
        dp[i][j] = 0;
        rep(k, t[i]+1){
            if(j-k>=0){
                dp[i][j] = (dp[i][j] + dp[i-1][j-k] * combi(k+i-1, i-1)) % 998244353;
            }
        }
    }
    ll res = 0;
    rep(i, K+1){
        cout << dp[n-1][i] << endl;
        res = (res + dp[n-1][i]) % 998244353;
    }
    cout << res << endl;
}
