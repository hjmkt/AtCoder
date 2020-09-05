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

    ll N, M, X;
    cin >> N >> M >> X;
    vll C(N);
    vvll A(N, vll(M));
    rep(i, N){
        cin >> C[i];
        rep(j, M) cin >> A[i][j];
    }

    ll m = LLONG_MAX;
    rep(b, 1<<N){
        bool valid = true;
        rep(i, M){
            ll tmp = 0;
            rep(j, N){
                if((b>>j)&1) tmp += A[j][i];
            }
            valid &= tmp>=X;
        }
        ll total = 0;
        rep(i, N){
            if((b>>i)&1) total += C[i];
        }
        if(valid) m = min(m, total);
    }
    if(m==LLONG_MAX) cout << -1 << endl;
    else cout << m << endl;
}
