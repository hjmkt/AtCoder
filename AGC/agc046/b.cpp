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

    ll A, B, C, D;
    cin >> A >> B >> C >> D;

    vvll dp(C-A+1, vll(D-B+1, 0));
    dp[0][0] = 1;
    rep(i, C-A) dp[i+1][0] = dp[i][0] * B % 998244353;
    rep(i, D-B) dp[0][i+1] = dp[0][i] * A % 998244353;
    REP(i, 1, C-A+1) REP(j, 1, D-B+1){
        dp[i][j] = (dp[i-1][j]*(j+B) + dp[i][j-1]*(i+A) - dp[i-1][j-1]*(j+B-1)*(i+A-1)) % 998244353;
        dp[i][j] = (dp[i][j]+998244353) % 998244353;
    }
    cout << dp[C-A][D-B] << endl;
}
