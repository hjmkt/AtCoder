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

template<typename A, typename B>
struct pair_hash{
    inline size_t operator()(const pair<A, B> &p) const{
        const auto h1 = hash<A>()(p.first);
        const auto h2 = hash<B>()(p.second);
        return h1^(h2<<18);
    }
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);

    ll N;
    cin >> N;
    vll x(N), y(N);
    rep(i, N) cin >> x[i] >> y[i];

    unordered_map<pair<int, int>, pair<int, int>, pair_hash<int, int>> par;
    rep(i, N) par[{x[i], y[i]}] = {x[i], y[i]};
    function<pair<int, int>(pair<int, int>)> root = [&](pair<int, int> p){
        if(par[p]==p) return p;
        return par[p] = root(par[p]);
    };
    function<void(pair<int, int>, pair<int, int>)> unite = [&](pair<int, int> p1, pair<int, int> p2){
        auto r1 = root(p1);
        auto r2 = root(p2);
        if(r1!=r2) par[r1] = r2;
    };

    vll xs(100001, 0), ys(100001, 0);
    rep(i, N){
        if(xs[x[i]]>0) unite({x[i], xs[x[i]]}, {x[i], y[i]});
        else xs[x[i]] = y[i];
        if(ys[y[i]]>0) unite({ys[y[i]], y[i]}, {x[i], y[i]});
        else ys[y[i]] = x[i];
    }

    ll ans = 0;
    map<pair<ll, ll>, set<pair<ll, ll>>> m;
    for(auto p : par){
        m[root(p.second)].insert(p.first);
    }
    for(auto p : m){
        auto s = p.second;
        unordered_set<ll> xs, ys;
        for(auto t : s){
            xs.insert(t.first);
            ys.insert(t.second);
        }
        ll n = xs.size() * ys.size() - s.size();
        ans += n;
    }
    cout << ans << endl;
}
