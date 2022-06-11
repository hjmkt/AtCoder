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
    vll S(N-1);
    rep(i, N-1) cin >> S[i];
    vll X(M);
    rep(i, M) cin >> X[i];

    vll d(N, 0);
    REP(i, 1, N){
        d[i] = S[i-1] - d[i-1];
    }
    umap<ll, ll> m;
    rep(i, N){
        if(i%2==0){
            rep(j, M) ++m[d[i]-X[j]];
        }
        else{
            rep(j, M) ++m[X[j]-d[i]];
        }
    }
    ll ans = 0;
    for(auto [_, v]: m){
        ans = max(ans, v);
    }
    cout << ans << endl;
}
