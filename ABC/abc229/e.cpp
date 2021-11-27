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

    ll N, M;
    cin >> N >> M;
    vll A(M), B(M);
    rep(i, M) cin >> A[i] >> B[i];

    vector<unordered_set<ll>> e(N);
    rep(i, M){
        e[A[i]-1].insert(B[i]-1);
        e[B[i]-1].insert(A[i]-1);
    }

    vll ans(N, 0);
    UnionFind uf(N);
    ll t = 0;
    REP(i, 1, N){
        ++t;
        for(ll v : e[N-i]){
            if(v>N-i){
                ll r1 = uf.root(v);
                ll t1 = uf.root(N-i);
                uf.unite(v, N-i);
                ll r2 = uf.root(v);
                ll t2 = uf.root(N-i);
                if(r1!=r2 || t1!=t2) --t;
            }
        }
        ans[N-i-1] = t;
    }
    rep(i, N){
        cout << ans[i] << endl;
    }
}
