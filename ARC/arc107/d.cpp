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

    vvll dp(N+1, vll(N+1, -1));

    function<ll(ll, ll)> solve = [&](ll n, ll k){
        if(n<=0 || k<=0) return 0ll;
        if(k>n) return 0ll;
        if(n==k) return 1ll;
        if(dp[n][k]>=0) return dp[n][k];

        dp[n][k] = (solve(n-1, k-1) + solve(n, 2*k)) % 998244353;
        return dp[n][k];
    };

    ll ans = solve(N, K);
    cout << ans << endl;
}
