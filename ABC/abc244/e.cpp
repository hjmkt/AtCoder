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

    ll N, M, K, S, T, X;
    cin >> N >> M >> K >> S >> T >> X;
    vll U(M), V(M);
    rep(i, M) cin >> U[i] >> V[i];

    vector<set<ll>> e(N);
    rep(i, M){
        e[U[i]-1].insert(V[i]-1);
        e[V[i]-1].insert(U[i]-1);
    }

    vvvll dp(N, vvll(K+1, vll(2, 0)));
    dp[S-1][0][0] = 1;
    REP(j, 1, K+1){
        rep(i, N){
            for(ll n: e[i]){
                if(i==X-1){
                    dp[i][j][0] = (dp[i][j][0]+dp[n][j-1][1]) % 998244353;
                    dp[i][j][1] = (dp[i][j][1]+dp[n][j-1][0]) % 998244353;
                }
                else{
                    dp[i][j][0] = (dp[i][j][0]+dp[n][j-1][0]) % 998244353;
                    dp[i][j][1] = (dp[i][j][1]+dp[n][j-1][1]) % 998244353;
                }
            }
        }
    }
    cout << dp[T-1][K][0] << endl;
}
