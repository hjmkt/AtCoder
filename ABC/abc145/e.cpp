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

int main(){
    ll n, t;
    cin >> n >> t;
    vector<pair<ll, ll>> ab(n);
    rep(i, n) cin >> ab[i].first >> ab[i].second;

    sort(all(ab), [](auto lhs, auto rhs){
        if(lhs.first<rhs.first) return true;
        else if(lhs.first==rhs.first) return lhs.second<rhs.second;
        else return false;
    });

    vll a(n), b(n);
    rep(i, n) a[i] = ab[i].first;
    rep(i, n) b[i] = ab[i].second;

    vvll dp(n, vll(t, 0));
    ll res = 0;
    rep(i, n){
        rep(j, t){
            if(i==0) dp[i][j] = j==a[i]? b[i] : 0;
            else if(j-a[i]>=0) dp[i][j] = max(dp[i-1][j], dp[i-1][j-a[i]]+b[i]);
            else dp[i][j] = dp[i-1][j];
        }
        rep(j, t){
            res = max(res, dp[i][j]);
            if(i>0) res = max(res, dp[i-1][j]+b[i]);
        }
    }
    cout << res << endl;
}
