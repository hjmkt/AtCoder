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
    vll X(Q);
    rep(i, Q) cin >> X[i];

    sort(all(A));
    vll S(N+1, 0);
    rep(i, N){
        S[i+1] = S[i] + A[i];
    }

    rep(i, Q){
        ll lb = 0, ub = N-1;
        while(lb<ub){
            ll m = (lb+ub) / 2;
            if(A[m]<X[i]){
                lb = m + 1;
            }
            else {
                ub = m;
            }
        }
        ll n = A[lb]>=X[i]? lb : N;
        ll ans = X[i]*n - S[n] + (S.back()-S[n]) - X[i]*(N-n);
        cout << ans << endl;
    }
}
