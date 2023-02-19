#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;
template<class T> using uset = unordered_set<T>;
template<class T, class U> using umap = unordered_map<T, U>;
template<class T> using mset = multiset<T>;
template<class T, class U> using mmap = multimap<T, U>;
template<class T> using umset = unordered_multiset<T>;
template<class T, class U> using ummap = unordered_multimap<T, U>;

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

    UnionFind uf(N);
    ll ans = 0;
    rep(i, M){
        if(uf.root(A[i]-1)==uf.root(B[i]-1)) ++ans;
        uf.unite(A[i]-1, B[i]-1);
    }
    cout << ans << endl;
}
