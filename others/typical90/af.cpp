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

    ll N;
    cin >> N;
    vvll A(N, vll(N, 0));
    rep(i, N) rep(j, N) cin >> A[i][j];
    ll M;
    cin >> M;
    vll X(M), Y(M);
    rep(i, M) cin >> X[i] >> Y[i];

    vector<uset<ll>> s(N);
    rep(i, M){
        s[X[i]-1].insert(Y[i]-1);
        s[Y[i]-1].insert(X[i]-1);
    }

    vll indices(N);
    rep(i, N) indices[i] = i;
    ll m = LLONG_MAX;
    do {
        bool valid = true;
        rep(i, N-1){
            if(s[indices[i]].find(indices[i+1])!=s[indices[i]].end()){
                valid = false;
                break;
            }
        }
        if(valid){
            ll t = 0;
            rep(i, N){
                t += A[indices[i]][i];
            }
            m = min(m, t);
        }
    } while(next_permutation(all(indices)));

    if(m<LLONG_MAX) cout << m << endl;
    else cout << -1 << endl;
}
