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

    ll N, Q;
    cin >> N >> Q;
    vll A(N);
    rep(i, N) cin >> A[i];
    vll T(Q), x(Q), y(Q);
    rep(i, Q) cin >> T[i] >> x[i] >> y[i];

    vll indices(N);
    rep(i, N) indices[i] = i;
    ll shift = 0;
    rep(i, Q){
        if(T[i]==1) swap(indices[((x[i]-1-shift)%N+N)%N], indices[((y[i]-1-shift)%N+N)%N]);
        else if(T[i]==2) ++shift;
        else cout << A[indices[((x[i]-1-shift)%N+N)%N]] << endl;
    }
}
