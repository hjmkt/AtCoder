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
    vll D(N), C(N), S(N);
    rep(i, N) cin >> D[i] >> C[i] >> S[i];

    vector<tuple<ll, ll, ll>> DCS(N);
    rep(i, N) DCS[i] = {D[i], C[i], S[i]};
    sort(all(DCS), [](auto l, auto r){ return get<0>(l)<get<0>(r); });

    vvll dp(N+1, vll(5001, 0));
    REP(i, 1, N+1){
        auto [d, c, s] = DCS[i-1];
        REP(j, 1, 5001){
            dp[i][j] = dp[i-1][j];
            if(j-c<0 || d<j) continue;
            dp[i][j] = max(dp[i][j], dp[i-1][j-c] + s);
        }
    }
    cout << *max_element(all(dp[N])) << endl;
}
