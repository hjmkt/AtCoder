#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;
template<class T> using uset = unordered_set<T>;
template<class T, class U> using umap = unordered_map<T, U>;

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

    ll x[3], y[3];
    rep(i, 3) cin >> x[i] >> y[i];
    map<ll, ll> mx, my;
    rep(i, 3){
        ++mx[x[i]];
        ++my[y[i]];
    }
    ll ans_x, ans_y;
    for(auto p: mx){
        if(p.second==1) ans_x = p.first;
    }
    for(auto p: my){
        if(p.second==1) ans_y = p.first;
    }
    cout << ans_x << " " << ans_y << endl;
}
