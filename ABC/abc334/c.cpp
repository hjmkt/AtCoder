#include <bits/stdc++.h>
#include <climits>

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

    sort(all(A));
    if(K%2==0){
        ll ans = 0;
        rep(i, K/2) ans += abs(A[2*i+1] - A[2*i]);
        cout << ans << endl;
    }
    else{
        vll t0(K/2+1), t1(K/2+1);
        rep(i, K/2) t0[i+1] = t0[i] + abs(A[2*i+1] - A[2*i]);
        rep(i, K/2) t1[i+1] = t1[i] + abs(A[2*i+2] - A[2*i+1]);
        ll ans = LLONG_MAX;
        rep(i, (K+1)/2){
            ll v = t0[i] + t1[K/2] - t1[i];
            ans = min(ans, v);
        }
        if(ans==LLONG_MAX) cout << 0 << endl;
        else cout << ans << endl;
    }
}
