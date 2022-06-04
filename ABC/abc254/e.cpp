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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);

    ll N, M;
    cin >> N >> M;
    vll a(M), b(M);
    rep(i, M) cin >> a[i] >> b[i];
    ll Q;
    cin >> Q;
    vll x(Q), k(Q);
    rep(i, Q) cin >> x[i] >> k[i];

    vector<uset<ll>> g(N);
    rep(i, M){
        g[a[i]-1].insert(b[i]-1);
        g[b[i]-1].insert(a[i]-1);
    }
    rep(i, Q){
        uset<ll> s = {x[i]-1};
        rep(j, k[i]){
            uset<ll> t;
            for(ll n: s){
                t.insert(n);
                for(ll m: g[n]) t.insert(m);
            }
            s = t;
        }
        ll ans = 0;
        for(ll n: s) ans += n+1;
        cout << ans << endl;
    }
}
