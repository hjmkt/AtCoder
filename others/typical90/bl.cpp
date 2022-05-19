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
    vll L(Q), R(Q), V(Q);
    rep(i, Q) cin >> L[i] >> R[i] >> V[i];

    vll d(N-1, 0);
    rep(i, N-1) d[i] = A[i+1]-A[i];
    ll s = 0;
    rep(i, N-1) s += abs(d[i]);
    rep(i, Q){
        if(L[i]>1) s += abs(d[L[i]-2]+V[i]) - abs(d[L[i]-2]);
        if(R[i]<N) s += abs(d[R[i]-1]-V[i]) - abs(d[R[i]-1]);
        if(L[i]>1) d[L[i]-2] += V[i];
        if(R[i]<N) d[R[i]-1] -= V[i];
        cout << s << endl;
    }
}
