#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;

#define REP(i, n, m) for(ll i=n; i<(ll)m; ++i)
#define IREP(i, n, m) for(ll i=n-1; i>=m; --i)
#define rep(i, n) REP(i, 0, n)
#define irep(i, n) IREP(i, n, 0)
#define all(v) v.begin(), v.end()
#define vprint(v) for(auto e:v){cout<<e<<" ";};cout<<endl;
#define vvprint(vv) for(auto v:vv)vprint(v);

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);

    ll N, M;
    cin >> N >> M;
    vll A(N), B(N), C(N);
    vll D(M), E(M), F(M);
    rep(i, N) cin >> A[i] >> B[i] >> C[i];
    rep(i, M) cin >> D[i] >> E[i] >> F[i];

    vll xs, ys;
    rep(i, N){
        xs.push_back(A[i]);
        xs.push_back(B[i]);
        ys.push_back(C[i]);
    }
    rep(i, M){
        ys.push_back(E[i]);
        ys.push_back(F[i]);
        xs.push_back(D[i]);
    }
    sort(all(xs));
    sort(all(ys));
    unordered_map<ll, ll> xm, ym;
    rep(i, xs.sizee()) xm[xs[i]] = i;
    rep(i, ys.sizee()) ym[ys[i]] = i;

    rep(i, N){
        A[i] = xm[A[i]];
        B[i] = xm[B[i]];
        C[i] = ym[C[i]];
    }
    rep(i, M){
        E[i] = ym[E[i]];
        F[i] = ym[F[i]];
        D[i] = xm[D[i]];
    }
}
