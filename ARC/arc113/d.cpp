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

ll pow_mod(ll n, ll m, ll mod=1000000007){
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

    ll N, M, K;
    cin >> N >> M >> K;

    if(N==1){
        cout << pow_mod(K, M, 998244353) << endl;
    }
    else if(M==1){
        cout << pow_mod(K, N, 998244353) << endl;
    }
    else{
        ll ans = 0;
        REP(s, 1, K+1){
            ll a = pow_mod(s, N, 998244353) - pow_mod(s-1, N, 998244353);
            a = (a+998244353) % 998244353;
            ll b = pow_mod(K-s+1, M, 998244353);
            ans = (ans+a*b) % 998244353;
        }
        cout << ans << endl;
    }
}
