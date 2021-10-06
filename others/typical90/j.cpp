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
#define vvprint(vv) for(auto v:vv){vprint(v)};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);

    ll N;
    cin >> N;
    vll C(N), P(N);
    rep(i, N) cin >> C[i] >> P[i];
    ll Q;
    cin >> Q;
    vll L(Q), R(Q);
    rep(i, Q) cin >> L[i] >> R[i];

    vvll S(2, vll(N+2, 0));
    ll s0 = 0, s1 = 0;
    rep(i, N) {
        if(C[i]==1){
            s0 += P[i];
        }
        else {
            s1 += P[i];
        }
        S[0][i+1] = s0;
        S[1][i+1] = s1;
    }
    rep(i, Q) {
        ll a0 = S[0][R[i]] - S[0][L[i]-1];
        ll a1 = S[1][R[i]] - S[1][L[i]-1];
        cout << a0 << " " << a1 << endl;
    }
}
