#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;

#define REP(i, x, n) for(ll i=x; i<(ll)n; ++i)
#define rep(i, n) REP(i, 0, n)
#define all(v) v.begin(), v.end()

int main(){
    ll N, K;
    cin >> N >> K;

    vvll dp(K+1, vll((ll)sqrt(N)*2+1, -1));
    vll t;
    t.push_back(N/1);
    REP(i, 2, (ll)sqrt(N)+1){
        if(N/i<t[t.size()-1]) t.push_back(N/i);
    }
    for(ll i=sqrt(N); i>=1; --i){
        if(i<t[t.size()-1]) t.push_back(i);
    }
    function<ll(ll, ll)> solve = [&](ll k, ll n){
        if(n<0) return 0ll;
        if(dp[k][n]>=0) return dp[k][n];
        if(k==1){
            ll r = solve(k, n-1) + N/t[n] - N/(t[n]+1);
            r %= 1000000007;
            dp[k][n] = r;
            return r;
        }
        ll p = N/t[n] - N/(t[n]+1);
        ll b = lower_bound(all(t), N/t[n], [](auto l, auto r){ return l>r; }) - t.begin();
        ll count = b>=t.size()? 0 : solve(k-1, b) * p % 1000000007;
        dp[k][n] = (solve(k, n-1) + count) % 1000000007;
        return dp[k][n];
    };
    ll a = solve(K, t.size()-1);
    cout << a << endl;
}
