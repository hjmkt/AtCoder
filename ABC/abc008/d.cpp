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

struct pair_hash{
    inline size_t operator()(const pair<pair<ll, ll>, pair<ll, ll>> &p) const{
        const auto h1 = hash<ll>()(p.first.first);
        const auto h2 = hash<ll>()(p.first.second);
        const auto h3 = hash<ll>()(p.second.first);
        const auto h4 = hash<ll>()(p.second.second);
        return h1^(h2<<10)^(h3<<20)^(h4<<30);
    }
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);

    ll W, H, N;
    cin >> W >> H >> N;
    vll X(N), Y(N);
    rep(i, N) cin >> X[i] >> Y[i];

    unordered_map<pair<pair<ll, ll>, pair<ll, ll>>, ll, pair_hash> dp;

    function<ll(ll, ll, ll, ll)> solve = [&](ll x1, ll y1, ll x2, ll y2){
        if(x1>x2 || y1>y2) return 0ll;
        auto it = dp.find({{x1, y1}, {x2, y2}});
        if(it!=dp.end()) return it->second;
        ll mx = 0;
        rep(i, N){
            ll x3 = X[i], y3 = Y[i];
            if(x3<x1 || x3>x2 || y3<y1 || y3>y2) continue;
            ll t = x2-x3 + x3-x1 + y2-y3 + y3-y1 + 1;
            t += solve(x1, y1, x3-1, y3-1) + solve(x3+1, y1, x2, y3-1) + solve(x1, y3+1, x3-1, y2) + solve(x3+1, y3+1, x2, y2);
            mx = max(mx, t);
        }
        dp[{{x1, y1}, {x2, y2}}] = mx;
        return mx;
    };

    cout << solve(1, 1, W, H) << endl;
}
