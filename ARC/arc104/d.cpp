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

    ll N, K, M;
    cin >> N >> K >> M;
    vvll dp(N*N+1, vll(N+1, 0));
    rep(n, N*N+1){
        if(n==0){
            dp[n][0] = K;
            rep(k, K) dp[n][k+1] = 1;
            continue;
        }
        IREP(k, N+1, 1){
            if(k==N){
                dp[n][k] = n%k==0? 1 : 0;
                continue;
            }
            dp[n][k] = 0;
            for(ll d=0; d*k<=n&&d<=K; ++d) dp[n][k] = (dp[n][k]+dp[n-d*k][k+1]) % M;
        }
    }
    REP(x, 1, N+1){
        ll count = 0;
        rep(k, K+1){
            if(k==0){
                if(x==0) ++count;
                continue;
            }
            ll t = x*k;
            count = (count+dp[t][0]) % M;
        }
        cout << count << endl;
    }
}
