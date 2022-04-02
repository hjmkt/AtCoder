#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;
template<class T> using uset = unordered_set<T>;
template<class T, class U> using umap = unordered_map<T, U>;

#define REP(i, n, m) for(ll i=n; i<(ll)m; ++i)
#define IREP(i, n, m) for(ll i=n-1; i>=m; --i)
#define rep(i, n) REP(i, 0, n)
#define irep(i, n) IREP(i, n, 0)
#define all(v) v.begin(), v.end()
#define vprint(v) for(auto e:v){cout<<e<<" ";};cout<<endl;
#define vvprint(vv) for(auto v:vv){vprint(v)};

ll MOD = 998244353;

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

    ll N, L;
    cin >> N >> L;
    vector<string> S(N);
    rep(i, N) cin >> S[i];

    vll indices(N);
    rep(i, N) indices[i] = i;
    ll ans = 0;

    function<void(set<char>, ll, ll)> combs = [&](set<char> s, ll last, ll count){
        if(last==N-1) return;
        REP(i, last+1, N){
            set<char> t;
            for(auto c: S[i]) if(s.find(c)!=s.end()) t.insert(c);
            ll n = t.size();
            ll alt = count%2==0? 1 : -1;
            ans = (ans + alt*pow_mod(n, L) + MOD) % MOD;
            combs(t, i, count+1);
        }
    };
    set<char> s;
    rep(i, 26) s.insert('a'+i);
    combs(s, -1, 0);
    cout << ans << endl;
}
