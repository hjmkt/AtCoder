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
    ll n;
    cin >> n;
    vll a(n);
    rep(i, n) cin >> a[i];
    vvll dp(n, vll(2, -1));
    dp[n-1][0] = a[n-1];
    dp[n-1][1] = -a[n-1];
    IREP(i, n-1, 1){
        dp[i][0] = max(a[i]+dp[i+1][0], -a[i]+dp[i+1][1]);
        dp[i][1] = max(-a[i]+dp[i+1][0], a[i]+dp[i+1][1]);
    }
    dp[0][0] = a[0] + dp[1][0];
    dp[0][1] = -a[0] + dp[1][1];
    cout << max(dp[0][0], dp[0][1]) << endl;
}
