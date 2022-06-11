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

    ll N, K;
    cin >> N >> K;
    vll A(K);
    rep(i, K) cin >> A[i];
    vll X(N), Y(N);
    rep(i, N) cin >> X[i] >> Y[i];
    vvll d(N, vll(N, 0));
    rep(i, N){
        rep(j, N){
            d[i][j] = (X[i]-X[j])*(X[i]-X[j]) + (Y[i]-Y[j])*(Y[i]-Y[j]);
        }
    }
    ll r = 0;
    rep(i, N){
        ll m = LLONG_MAX;
        rep(j, K){
            m = min(m, d[i][A[j]-1]);
        }
        r = max(r, m);
    }
    double ans = sqrt(r);
    cout << ans << endl;
}
