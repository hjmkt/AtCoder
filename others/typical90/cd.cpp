#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;
template<class T> using uset = unordered_set<T>;
template<class T, class U> using umap = unordered_map<T, U>;
template<class T> using mset = multiset<T>;
template<class T, class U> using mmap = multimap<T, U>;
template<class T> using umset = unordered_multiset<T>;
template<class T, class U> using ummap = unordered_multimap<T, U>;

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

    ll L, R;
    cin >> L >> R;

    ll mod = 1000000007;
    ll div2 = pow_mod(2, mod-2);
    ll b = 1;
    ll n = 1;
    ll ans = 0;
    while(true){
        ll l = b, r = max(b*10 - 1, l);
        if(r<L){
            b *= 10;
            ++n;
            continue;
        }
        l = max(l, L);
        r = min(r, R);
        ll d = r%mod * ((r+1)%mod) % mod * div2 % mod - l%mod * ((l-1)%mod) % mod * div2 % mod;
        d = d*n % mod;
        ans = (ans + d) % mod;
        if(b>R/10) break;
        b *= 10;
        ++n;
    }
    ans = (ans%mod+mod) % mod;
    cout << ans << endl;
}
