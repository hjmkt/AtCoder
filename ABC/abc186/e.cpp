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

ll gcd(ll n, ll m){
    while(true){
        if(n<m) swap(n, m);
        if(!m) break;
        n %= m;
    }
    return n;
}

pair<ll, ll> exgcd(ll a, ll b){
    if(b==0) return {1, 0};
    auto p = exgcd(b, a%b);
    return {p.second, p.first-a/b*p.second};
}

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

    ll T;
    cin >> T;
    rep(t, T){
        ll N, S, K;
        cin >> N >> S >> K;
        
        ll L = N-S;
        // Kx = L mod N
        // Kx - Ny = L
        ll g = gcd(K, N);
        if(L%g==0){
            K /= g;
            L /= g;
            N /= g;
            auto p = exgcd(K, N);
            ll a = (p.first*L%N+N) % N;
            cout << a << endl;
        }
        else{
            cout << -1 << endl;
        }
    }
}
