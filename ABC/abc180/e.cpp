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

    ll N;
    cin >> N;
    vvll p(N, vll(3, 0));
    rep(i, N) cin >> p[i][0] >> p[i][1] >> p[i][2];

    vvll dp(1ll<<(N-1), vll(N, 0));
    rep(b, 1ll<<(N-1)) rep(c, N){
        if(b==0){
            ll d = abs(p[c][0]-p[0][0]) + abs(p[c][1]-p[0][1]) + max(0ll, p[0][2]-p[c][2]);
            dp[0][c] = d;
            continue;
        }
        ll m = LLONG_MAX;
        rep(i, N-1){
            if((b>>i)&1){
                ll nb = b - (1<<i);
                ll d = dp[nb][i+1] + abs(p[c][0]-p[i+1][0]) + abs(p[c][1]-p[i+1][1]) + max(0ll, p[i+1][2]-p[c][2]);
                m = min(m, d);
            }
        }
        dp[b][c] = m;
    }
    cout << dp[(1ll<<(N-1))-1][0] << endl;
}
