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

class UnionFind{
    public:
        ll size;
        vll v;

        UnionFind(ll n){
            this->v = vll(n);
            rep(i, n) this->v[i] = i;
        }

        ll root(ll n){
            if(n!=v[n]) return v[n] = root(v[n]);
            return n;
        }

        void unite(ll l, ll r){
            ll lroot = root(l);
            ll rroot = root(r);
            if(lroot!=rroot) this->v[rroot] = lroot;
        }
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);

    ll H, W;
    cin >> H >> W;
    vector<string> S(H);
    rep(i, H) cin >> S[i];

    UnionFind uf(H+W);
    uf.unite(0, H-1);
    uf.unite(H-1, H);
    uf.unite(H, H+W-1);
    rep(h, H) rep(w, W){
        if(S[h][w]=='#') uf.unite(h, H+w);
    }
    unordered_set<ll> sh, sw;
    rep(i, H) sh.insert(uf.root(i));
    rep(i, W) sw.insert(uf.root(H+i));
    ll t = min(sh.size(), sw.size());
    cout << t-1 << endl;
}
