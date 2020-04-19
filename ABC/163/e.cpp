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
#define vvprint(vv) for(auto v:vv)vprint(v);

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);

    ll N;
    cin >> N;
    vll A(N);
    rep(i, N) cin >> A[i];

    vvll c(N, vll(2, 0));
    rep(i, N) c[i] = {A[i], i};
    sort(all(c), [&](auto x, auto y){ return x[0]>y[0]; });
    vvll dp(N+1, vll(N+1, 0));
    rep(i, N+1){
        rep(j, N+1-i){
            if(i>0) dp[i][j] = max(dp[i][j], dp[i-1][j]+(c[i+j-1][1]-i+1)*c[i+j-1][0]);
            if(j>0) dp[i][j] = max(dp[i][j], dp[i][j-1]+(N-j-c[i+j-1][1])*c[i+j-1][0]);
        }
    }
    ll res = 0;
    rep(i, N+1) res = max(res, dp[i][N-i]);
    cout << res << endl;
}
