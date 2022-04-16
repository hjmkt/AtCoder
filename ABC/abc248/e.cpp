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

ll gcd(ll n, ll m){
    while(true){
        if(n<m) swap(n, m);
        if(!m) break;
        n %= m;
    }
    return n;
}

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

    ll N, K;
    cin >> N >> K;
    vll X(N), Y(N);
    rep(i, N) cin >> X[i] >> Y[i];

    if(K==1){
        cout << "Infinity" << endl;
        return 0;
    }

    map<pair<ll, ll>, set<pair<ll, ll>>> m;

    rep(i, N) REP(j, i, N){
        ll dx = X[j] - X[i];
        ll dy = Y[j] - Y[i];
        if (abs(dx)>0 && abs(dy)>0) {
            ll g = gcd(abs(dx), abs(dy));
            dx /= g;
            dy /= g;
        }
        else if(abs(dx)>0) dx /= abs(dx);
        else if(abs(dy)>0) dy /= abs(dy);
        if(dx<0){
            dx = -dx;
            dy = -dy;
        }
        else if(dx==0){
            dy = abs(dy);
        }
        m[{dx, dy}].insert({i, j});
    }

    ll ans = 0;
    for(auto [d, s]: m){
        UnionFind uf(N);
        for(auto p: s){
            uf.unite(p.first, p.second);
        }
        map<ll, ll> count;
        rep(i, N){
            ++count[uf.root(i)];
        }
        for(auto [_, k]: count){
            if(k>=K) ++ans;
        }
    }
    cout << ans << endl;
}
