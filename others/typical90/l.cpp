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

    ll H, W, Q;
    cin >> H >> W >> Q;

    UnionFind uf(H*W);
    vector<bool> filled(H*W, false);

    rep(i, Q){
        ll t;
        cin >> t;
        if(t==1){
            ll r, c;
            cin >> r >> c;
            filled[(r-1)*W+c-1] = true;
            if(r>1 && filled[(r-2)*W+c-1]) uf.unite((r-1)*W+c-1, (r-2)*W+c-1);
            if(r<H && filled[r*W+c-1]) uf.unite((r-1)*W+c-1, r*W+c-1);
            if(c>1 && filled[(r-1)*W+c-2]) uf.unite((r-1)*W+c-1, (r-1)*W+c-2);
            if(c<W && filled[(r-1)*W+c]) uf.unite((r-1)*W+c-1, (r-1)*W+c);
        }
        else{
            ll ra, ca, rb, cb;
            cin >> ra >> ca >> rb >> cb;
            if(filled[(ra-1)*W+ca-1] && filled[(rb-1)*W+cb-1] && uf.root((ra-1)*W+ca-1)==uf.root((rb-1)*W+cb-1)) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
}
