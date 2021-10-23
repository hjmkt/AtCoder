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

ll pow_mod(ll n, ll m, ll mod=998244353){
    ll a = 1;
    while(m>0){
        if(m&1) a = a*n % mod;
        n = n*n % mod;
        m >>= 1;
    }
    return a;
}

ll combi(ll n, ll m, ll mod=998244353){
    static const ll N_MAX = 200001;
    static vll fac(N_MAX+1, -1);
    static vll ifac(N_MAX+1, -1);

    if(fac[0]<0){
        fac[0] = ifac[0] = 1;
        rep(i, N_MAX){
            fac[i+1] = fac[i] * (i+1) % mod;
            ifac[i+1] = ifac[i] * pow_mod(i+1, mod-2, mod) % mod;
        }
    }

    if(n<=0 && m<=0) return 1;
    if(n<m || n<0) return 0;
    return (ifac[n-m] * ifac[m] % mod) * fac[n] % mod;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);

    string S;
    cin >> S;
    ll N = S.length();

    ll a = 0;

    rep(i, N-1){
        ll t = pow_mod(2, N);
        t = t * (ll)(S[i]-'0') % 998244353;;
        t = t * (pow_mod(5, N-i-1)+998244352) % 998244353;
        t = t * pow_mod(16, 998244351) % 998244353;
        a = (a+t) % 998244353;
        a = (a+(ll)(S[i]-'0')*pow_mod(10, N-i-1)*pow_mod(2, i)) % 998244353;
    }
    a = (a+(ll)(S[N-1]-'0')*pow_mod(2, N-1)) % 998244353;
    cout << a << endl;
}
