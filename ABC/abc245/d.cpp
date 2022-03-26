#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;
template<class T> using uset = unordered_set<T>;
template<class T, class U> using umap = unordered_map<T, U>;

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
    vll A(N+1), C(N+M+1);
    rep(i, N+1) cin >> A[i];
    rep(i, N+M+1) cin >> C[i];

    vll B(M+1, 0);
    while(A[0]==0){
        rep(j, N) A[j] = A[j+1];
        A[N] = 0;
        rep(j, N+M) C[j] = C[j+1];
        C[N+M] = 0;
    }
    rep(i, M+1){
        B[i] = C[0]/A[0];
        rep(j, N+1) C[j] -= B[i]*A[j];
        rep(j, N+M) C[j] = C[j+1];
        C[N+M] = 0;
    }
    rep(i, M) cout << B[i] << " ";
    cout << B[M] << endl;
}
