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

ll M = 998244353;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);

    ll X;
    cin >> X;

    unordered_map<ll, ll> m;

    function<ll(ll)> solve = [&](ll x){
        if(x<=4){
            return x;
        }
        else{
            if(m.find(x)!=m.end()) return m[x];
            ll y = x / 2;
            ll z = (x+1) / 2;
            ll a = solve(y) % M;
            ll b = solve(z) % M;
            m[x] = a*b % M;
            return m[x];
        }
    };
    ll ans = solve(X);
    cout << ans << endl;
}
