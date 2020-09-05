#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;

#define REP(i, n, m) for(ll i=n; i<(ll)m; ++i)
#define IREP(i, n, m) for(ll i=n-1; i>=m; --i)
#define rep(i, n) REP(i, 0, n)
#define irep(i, n) IREP(i, n, 0)
#define all(v) v.begin(), v.end()

int main(){
    ll n, m;
    cin >> n >> m;
    vll a(m), b(m);
    vll f(m);
    rep(i, m){
        cin >> a[i] >> b[i];
        rep(j, b[i]){
            ll c;
            cin >> c;
            f[i] |= 1<<(c-1);
        }
    }

    ll dp[m+1][1<<12] = {};
    rep(i, m+1) rep(j, 1<<n) dp[i][j] = -2;
    function<ll(ll, ll)> solve = [&](ll nd, ll o){
        if(dp[nd][o]>=-1) return dp[nd][o];
        if(o==(1<<n)-1) return dp[nd][o]=0ll;
        if(nd>=m) return dp[nd][o]=-1ll;
        ll oo = o | f[nd];
        ll t0 = solve(nd+1, o);
        ll t1 = solve(nd+1, oo);
        ll t = 1ll<<60;
        t = t0>=0? min(t, t0) : t;
        t = t1>=0? min(t, t1+a[nd]) : t;
        t = t<(1ll<<60)? t : -1;
        dp[nd][o] = t;
        return t;
    };
    cout << solve(0, 0) << endl;
}
