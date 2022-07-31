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
    vll U(M), V(M);
    rep(i, M) cin >> U[i] >> V[i];

    vector<uset<ll>> g(N);
    rep(i, M){
        g[U[i]-1].insert(V[i]-1);
        g[V[i]-1].insert(U[i]-1);
    }
    ll ans = 0;
    rep(a, N){
        REP(b, a+1, N){
            REP(c, b+1, N){
                if(g[a].find(b)!=g[a].end() && g[b].find(c)!=g[b].end() && g[c].find(a)!=g[c].end()){
                    ++ans;
                }
            }
        }
    }
    cout << ans << endl;
}
