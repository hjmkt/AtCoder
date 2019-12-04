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

ll pow_mod(ll n, ll m, ll mod=1000000007){
    ll a = 1;
    while(m>0){
        if(m&1) a = a*n % mod;
        n = n*n % mod;
        m >>= 1;
    }
    return a;
}

ll combi(ll n, ll m, ll mod=1000000007){
    static const ll N_MAX = 100000;
    static vll fac(N_MAX+1, -1);
    static vll ifac(N_MAX+1, -1);

    if(fac[0]<0){
        fac[0] = ifac[0] = 1;
        rep(i, N_MAX){
            fac[i+1] = fac[i] * (i+1) % mod;
            ifac[i+1] = ifac[i] * pow_mod(i+1, mod-2, mod) % mod;
        }
    }

    if(n<0 || m<0 || n<m) return 0;
    if(m==0) return 1;
    return (ifac[n-m] * ifac[m] % mod) * fac[n] % mod;
}

int main(){
    cout << setprecision(20);
    ll r, c, x, y, d, l;
    cin >> r >> c >> x >> y >> d >> l;

    ll count = (r-x+1) * (c-y+1) % 1000000007;
    ll s = d + l;
    if(s<=1 && (x>=2||y>=2)){
        cout << 0 << endl;
    }
    else{
        count = (count*combi(s, d)) % 1000000007;
        ll m = combi(x*y, s);
        m -= 2*(x>=1? combi((x-1)*y, s) : 0) + 2*(y>=1? combi(x*(y-1), s) : 0);
        m += (x>=2? combi((x-2)*y, s) : 0) + (y>=2? combi(x*(y-2), s) : 0) + 4*(x>=1&&y>=1? combi((x-1)*(y-1), s) : 0);
        m -= 2*(x>=2&&y>=1? combi((x-2)*(y-1), s) : 0) + 2*(x>=1&&y>=2? combi((x-1)*(y-2), s) : 0);
        m += (x>=2&&y>=2? combi((x-2)*(y-2), s) : 0);
        m = (m%1000000007+1000000007) % 1000000007;

        count = count*m % 1000000007;
        cout << count << endl;
    }
}
