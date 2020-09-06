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

vvll matmul(vvll &A, vvll &B, ll mod){
    ll n = A.size();
    vvll C(n, vll(n, 0));
    rep(i, n) rep(j, n) rep(k, n){
        C[i][j] = (C[i][j] + (A[i][k]%mod) * (B[k][j]%mod) % mod) % mod;
    }
    return C;
}

vvll mat_pow_mod(vvll &A, ll m, ll mod=1000000007){
    ll n = A.size();
    vvll X(n, vll(n, 0));
    rep(i, n) rep(j, n) X[i][j] = A[i][j];
    vvll B(n, vll(n, 0));
    rep(i, n) B[i][i] = 1;
    while(m>0){
        if(m&1) B = matmul(B, X, mod);
        X = matmul(X, X, mod);
        m >>= 1;
    }
    return B;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);

    ll L, A, B, M;
    cin >> L >> A >> B >> M;

    ll m = A + B*(L-1);
    ll d = 0;
    ll t = m;
    while(t>0){
        ++d;
        t /= 10;
    }

    vll c(d+1, 0);
    REP(i, 1, d+1){
        ll p = 1;
        rep(j, i-1) p *= 10;
        ll m1 = min(p*10 - 1, m) - A;
        ll m2 = min(p - 1, m) - A;
        ll c1 = max(0ll, m1/B + (m1>=0? 1 : 0));
        ll c2 = max(0ll, m2/B + (m2>=0? 1 : 0));
        c[i] = c1 - c2;
    }
    vvll T(3, vll(3, 0));
    T[0][0] = T[1][1] = T[2][2] = 1;
    REP(i, 1, d+1){
        vvll R = {{pow_mod(10, i, M), 0, 0}, {1, 1, 0}, {0, B, 1}};
        vvll Q = mat_pow_mod(R, c[i], M);
        T = matmul(T, Q, M);
    }
    ll ans = ((A%M) * T[1][0] + T[2][0]) % M;
    cout << ans << endl;
}
