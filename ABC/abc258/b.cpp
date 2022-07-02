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

    ll N;
    cin >> N;
    vvll A(N, vll(N));
    vector<string> S(N);
    rep(i, N) cin >> S[i];
    rep(i, N) rep(j, N){
        A[i][j] = S[i][j] - '0';
    }

    ll ans = 0;
    vvll dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
    rep(i, N) rep(j, N){
        for(auto d: dirs){
            ll dx = d[0], dy = d[1];
            ll n = 0;
            rep(k, N){
                ll x = ((j+dx*k)%N+N) % N;
                ll y = ((i+dy*k)%N+N) % N;
                n = n*10 + A[y][x];
            }
            ans = max(ans, n);
        }
    }
    cout << ans << endl;
}
