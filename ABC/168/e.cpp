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

template<typename A, typename B>
struct pair_hash{
    inline size_t operator()(const pair<A, B> &p) const{
        const auto h1 = hash<A>()(p.first);
        const auto h2 = hash<B>()(p.second);
        return h1^(h2<<18);
    }
};

ll gcd(ll n, ll m){
    while(true){
        if(n<m) swap(n, m);
        if(!m) break;
        n %= m;
    }
    return n;
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

    ll N;
    cin >> N;
    vll A(N), B(N);
    rep(i, N) cin >> A[i] >> B[i];

    unordered_map<pair<ll, ll>, pair<ll, ll>, pair_hash<ll, ll>> m;
    rep(i, N){
        ll a = A[i];
        ll b = B[i];
        ll g = gcd(abs(a), abs(b));
        if(g>0){
            a /= g;
            b /= g;
        }
        if(a<0){
            a = -a;
            b = -b;
        }
        else if(a==0) b = b==0? 0 : 1;

        ll oa = -b;
        ll ob = a;
        ll og = gcd(abs(oa), abs(ob));
        if(og>0){
            oa /= og;
            ob /= og;
        }
        if(oa<0){
            oa = -oa;
            ob = -ob;
        }
        else if(oa==0) ob = ob==0? 0 : 1;

        if(b>ob){
            if(m.find({a, b})!=m.end()){
                ++m[{a, b}].first;
            }
            else{
                m[{a, b}] = {1, 0};
            }
        }
        else{
            if(m.find({oa, ob})!=m.end()){
                ++m[{oa, ob}].second;
            }
            else{
                m[{oa, ob}] = {0, 1};
            }
        }
    }

    ll ans = 1;
    ll r = 0;
    for(auto p : m){
        auto k = p.first;
        auto v = p.second;
        if(k.first==0 && k.second==0){
            r = v.first + v.second;
            continue;
        }
        ll t = pow_mod(2, v.first) + pow_mod(2, v.second) - 1;
        ans = ans*t % 1000000007;
    }
    ans = (ans+r-1+1000000007) % 1000000007;

    cout << ans << endl;
}
