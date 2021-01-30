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

    ll N, M;
    cin >> N >> M;
    vll A(M), B(M);
    rep(i, M) cin >> A[i] >> B[i];
    ll K;
    cin >> K;
    vll C(K), D(K);
    rep(i, K) cin >> C[i] >> D[i];

    ll ans = 0;
    rep(bits, 1<<K){
        vll p(N, 0);
        rep(k, K){
            ll b = (bits>>k) & 1;
            if(b==0) ++p[C[k]-1];
            else ++p[D[k]-1];
        }
        ll c = 0;
        rep(m, M){
            if(p[A[m]-1]>=1 && p[B[m]-1]>=1) ++c;
        }
        ans = max(ans, c);
    }
    cout << ans << endl;
}
