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

ll MOD = 1000000007;

ll pow_mod(ll n, ll m, ll mod=MOD){
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

    ll N, B, K;
    cin >> N >> B >> K;
    vll c(K);
    rep(i, K) cin >> c[i];

    vvll dp(64, vll(B, 0));

    rep(i, K){
        ++dp[0][c[i]%B];
    }

    ll b10 = 10;
    rep(i, 63){
        rep(j, B){
            rep(k, B){
                dp[i+1][(j*b10+k)%B] = (dp[i+1][(j*b10+k)%B] + dp[i][j]*dp[i][k]) % MOD;
            }
        }
        b10 = (b10 * b10) % B;
    }

    vll ans(B, 0), tmp(B, 0);
    ans[0] = 1;
    b10 = 1;
    while(N>0){
        ll d = 0;
        while((1ull<<(d+1))<=N) ++d;
        rep(i, B) tmp[i] = 0;
        rep(i, B){
            rep(j, B){
                tmp[(i+j*b10)%B] = (tmp[(i+j*b10)%B] + ans[i]*dp[d][j]) % MOD;
            }
        }
        rep(i, B) ans[i] = tmp[i];
        b10 = (b10 * pow_mod(10, 1ull<<d, B)) % B;
        N -= 1ull<<d;
    }
    cout << ans[0] << endl;
}
