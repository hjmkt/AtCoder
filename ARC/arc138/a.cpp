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
    vll A(N);
    rep(i, N) cin >> A[i];
    vll B = {A[K]};
    REP(i, K+1, N) B.push_back(max(A[i], B.back()));
    ll ans = LLONG_MAX;
    rep(i, K){
        ll lb = K, ub = N-1;
        while(lb<ub){
            ll m = (lb+ub) / 2;
            if(A[K-i-1]<B[m-K]){
                ub = m;
            }
            else{
                lb = m + 1;
            }
        }
        if(A[K-i-1]<A[lb]){
            ans = min(ans, i+1+lb-K);
        }
    }
    if(ans<LLONG_MAX) cout << ans << endl;
    else cout << -1 << endl;
}
