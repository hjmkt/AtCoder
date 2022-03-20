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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);

    ll N, M;
    cin >> N >> M;
    vll u(M), v(M);
    rep(i, M) cin >> u[i] >> v[i];

    vector<set<ll>> e(N);
    rep(i, M){
        e[u[i]-1].insert(v[i]-1);
        e[v[i]-1].insert(u[i]-1);
    }

    vvll dp(N, vll(1<<N, LLONG_MAX));
    set<ll> cur;
    rep(i, N){
        cur.insert(i);
        dp[i][1<<i] = 1;
    }
    rep(i, 3*N){
        vvll tmp = dp;
        set<ll> next;
        for(ll n: cur){
            for(ll p: e[n]){
                rep(j, 1<<N){
                    ll l = dp[n][j];
                    if(l<LLONG_MAX) tmp[p][j^(1<<p)] = min(tmp[p][j^(1<<p)], l+1);
                }
                next.insert(p);
            }
        }
        dp = tmp;
        cur = next;
    }
    ll ans = 0;
    rep(i, 1<<N){
        ll m = LLONG_MAX;
        rep(j, N) m = min(m, dp[j][i]);
        ans += i==0? 0 : m;
    }
    cout << ans << endl;
}
