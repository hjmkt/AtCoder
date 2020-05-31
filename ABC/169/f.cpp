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

ll pow_mod(ll n, ll m, ll mod=998244353){
    ll a = 1;
    while(m>0){
        if(m&1) a = a*n % mod;
        n = n*n % mod;
        m >>= 1;
    }
    return a;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);

    ll N, S;
    cin >> N >> S;
    vll A(N);
    rep(i, N) cin >> A[i];

    vvll dp(N, vll(S+1, 0));
    dp[0][S] = 1;
    ll total = 0;
    rep(n, N){
        if(A[n]<=S) total = (total+dp[n][A[n]]*pow_mod(2, N-n-1)) % 998244353;
        if(n<N-1){
            rep(s, S+1){
                dp[n+1][s] = (dp[n+1][s]+dp[n][s]*2) % 998244353;
                if(s-A[n]>=0) dp[n+1][s-A[n]] = (dp[n+1][s-A[n]]+dp[n][s]) % 998244353;
            }
        }
    }
    cout << total << endl;
}
