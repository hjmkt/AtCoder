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
    vll A(N), B(M);
    rep(i, N) cin >> A[i];
    rep(i, M) cin >> B[i];

    vvll dp(N+1, vll(M+1, 0));
    rep(n, N) dp[n][M] = N-n;
    rep(m, M) dp[N][m] = M-m;
    irep(n, N){
        irep(m, M){
            ll d = 0;
            if(A[n]==B[m]){
                d = min({dp[n+1][m]+1, dp[n][m+1]+1, dp[n+1][m+1]});
            }
            else{
                d = min({dp[n+1][m]+1, dp[n][m+1]+1, dp[n+1][m+1]+1});
            }
            dp[n][m] = d;
        }
    }
    cout << dp[0][0] << endl;
}
