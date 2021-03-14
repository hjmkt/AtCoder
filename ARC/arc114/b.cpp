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

    ll N;
    cin >> N;
    vll f(N);
    rep(i, N) cin >> f[i];

    vector<bool> used(N, false);
    vvll cs;
    rep(i, N){
        if(used[i]) continue;
        unordered_set<ll> t = {i};
        vll c = {i};
        ll s = i;
        while(true){
            s = f[s] - 1;
            if(used[s]){
                rep(j, c.size()){
                    used[c[j]] = true;
                }
                break;
            }
            if(t.find(s)!=t.end()){
                bool r = true;
                vll nc;
                rep(j, c.size()){
                    if(c[j]==s) r = false;
                    if(!r) nc.push_back(c[j]);
                    used[c[j]] = true;
                }
                cs.push_back(nc);
                break;
            }
            t.insert(s);
            c.push_back(s);
        }
    }
    ll n = cs.size();
    ll ans = (pow_mod(2, n, 998244353) - 1 + 998244353) % 998244353;
    cout << ans << endl;
}
