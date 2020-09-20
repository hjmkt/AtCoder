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

    ll N, K;
    cin >> N >> K;
    vector<pair<ll, ll>> LR(K);
    rep(i, K) cin >> LR[i].first >> LR[i].second;

    sort(all(LR), [](auto l, auto r){ return l.first<r.first; });
    vll dp(N, 0), s(N+1, 0);
    dp[0] = 1;
    s[1] = 1;
    REP(i, 1, N){
        dp[i] = 0;
        rep(j, K){
            dp[i] += s[max(0ll, i-LR[j].first+1)] - s[max(0ll, i-LR[j].second)];
            dp[i] = (dp[i]+998244353)%998244353;
        }
        s[i+1] = (s[i] + dp[i]) % 998244353;
    }
    cout << dp[N-1] << endl;
}
