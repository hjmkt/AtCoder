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

    ll S;
    cin >> S;

    vll dp(S+1, 0);
    dp[0] = dp[3] = dp[4] = dp[5] = 1;
    REP(i, 6, S+1){
        ll s = 0;
        REP(j, 3, i+1){
            s = (s+dp[i-j]) % 1000000007;
        }
        dp[i] = s;
    }
    cout << dp[S] << endl;
}
