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

    ll H, W, M;
    cin >> H >> W >> M;
    vll X(M), Y(M);
    rep(i, M) cin >> X[i] >> Y[i];

    vector<set<ll>> xs(H+1);
    vector<set<ll>> ys(W+1);

    rep(i, M){
        xs[X[i]].insert(Y[i]);
        ys[Y[i]].insert(X[i]);
    }
    ll a = 1;
    ll w = xs[1].size()>0? *xs[1].begin()-1 : W;
    ll h = ys[1].size()>0? *ys[1].begin()-1 : H;
    REP(i, 2, w+1) a += ys[i].size()>0? *ys[i].begin() : H;
    REP(i, 2, h+1) a += xs[i].size()>0? *xs[i].begin() : W;
    cout << a << endl;
}
