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
    vll x(N), y(N);
    rep(i, N) cin >> x[i] >> y[i];

    vll idx(N);
    rep(i, N) idx[i] = i;
    sort(all(idx), [&](ll l, ll r){ return x[l]<x[r]; });

    vll p(N);
    rep(i, N) p[i] = i;
    function<ll(ll)> root = [&](ll x){
        if(p[x]==x) return x;
        return p[x] = root(p[x]);
    };
    function<void(ll, ll)> unite = [&](ll x, ll y){
        ll rx = root(x);
        ll ry = root(y);
        if(rx!=ry) p[rx] = ry;
    };
    ll m = y[idx[0]];
    ll mi = 0;
    function<bool(pair<ll, ll>, pair<ll, ll>)> comp = [](pair<ll, ll> l, pair<ll, ll> r){
        return l.first>r.first;
    };
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, decltype(comp)> q(comp);
    REP(i, 1, N){
        if(y[idx[i]]>m){
            unite(i, mi);
            while(!q.empty()){
                auto p = q.top();
                if(p.first<y[idx[i]]){
                    unite(p.second, i);
                    q.pop();
                }
                else break;
            }
        }
        else{
            q.push({m, mi});
            m = y[idx[i]];
            mi = i;
        }
    }
    unordered_map<ll, ll> mp;
    rep(i, N) ++mp[root(i)];

    vll inv(N);
    rep(i, N) inv[idx[i]] = i;
    rep(i, N) cout << mp[root(inv[i])] << endl;
}
