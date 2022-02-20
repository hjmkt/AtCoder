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

    ll N, X;
    cin >> N >> X;
    vll a(N), b(N);
    rep(i, N) cin >> a[i] >> b[i];

    vector<vector<bool>> dp(N+1, vector<bool>(X+1, false));
    dp[0][0] = true;
    REP(i, 1, N+1){
        rep(j, X+1){
            dp[i][j] = dp[i][j] || (j-a[i-1]>=0 && dp[i-1][j-a[i-1]]) || (j-b[i-1]>=0 && dp[i-1][j-b[i-1]]);
        }
    }
    if(dp[N][X]) cout << "Yes" << endl;
    else cout << "No" << endl;
}
