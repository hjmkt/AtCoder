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

    vvll dp(N, vll(9, 0));
    rep(i, 9) dp[0][i] = 1;
    rep(i, N-1){
        rep(j, 9){
            dp[i+1][j] =  (dp[i+1][j]+dp[i][j]) % 998244353;
            if(j>0) dp[i+1][j] =  (dp[i+1][j]+dp[i][j-1]) % 998244353;
            if(j<8) dp[i+1][j] =  (dp[i+1][j]+dp[i][j+1]) % 998244353;
        }
    }
    ll ans = 0;
    rep(i, 9) ans = (ans+dp[N-1][i]) % 998244353;
    cout << ans << endl;
}
