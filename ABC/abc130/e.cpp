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
#define vvprint(vv) for(auto v:vv)vprint(v);

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);

    ll N, M;
    cin >> N >> M;
    vll S(N), T(M);
    rep(i, N) cin >> S[i];
    rep(i, M) cin >> T[i];

    vvvvll dp(N, vvvll(M, vvll(2, vll(2, 0))));
    rep(i, N) dp[i][0][0][0] = 1;
    rep(i, M) dp[0][i][0][0] = 1;
    rep(i, N) dp[i][0][1][1] = S[i]==T[0]? 1 : 0;
    rep(i, M) dp[0][i][1][1] = S[0]==T[i]? 1 : 0;
    REP(i, 1, N) dp[i][0][0][1] = dp[i-1][0][0][1] + dp[i-1][0][1][1];
    REP(i, 1, M) dp[0][i][1][0] = dp[0][i-1][1][0] + dp[0][i-1][1][1];

    REP(i, 1, N) REP(j, 1, M){
        dp[i][j][0][0] = (dp[i][j-1][0][0] + dp[i][j-1][0][1]) % 1000000007;
        dp[i][j][0][1] = (dp[i-1][j][0][1] + dp[i-1][j][1][1]) % 1000000007;
        dp[i][j][1][0] = (dp[i][j-1][1][0] + dp[i][j-1][1][1]) % 1000000007;
        dp[i][j][1][1] = S[i]==T[j]? (dp[i-1][j-1][0][0]+dp[i-1][j-1][0][1]+dp[i-1][j-1][1][0]+dp[i-1][j-1][1][1])%1000000007 : 0;
    }
    ll ans = dp[N-1][M-1][0][0]+dp[N-1][M-1][0][1]+dp[N-1][M-1][1][0]+dp[N-1][M-1][1][1];
    ans %= 1000000007;
    cout << ans << endl;
}
