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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);

    ll a, N;
    cin >> a >> N;

    vll m(10000000, LLONG_MAX);
    vector<bool> b(10000000, false);

    function<ll(ll)> solve = [&](ll n){
        if(n==N) return 0ll;
        if(n>=10000000) return LLONG_MAX;
        if(n>=N*10) return LLONG_MAX;
        if(m[n]<LLONG_MAX) return m[n];
        if(b[n]) return LLONG_MAX;
        b[n] = true;
        ll x = solve(n*a);
        ll d = 1, t = n;
        while(t>0){
            d *= 10;
            t /= 10;
        }
        d /= 10;
        ll y = (n>=10&&n%10>0)? solve(d*(n%10) + n/10) : LLONG_MAX;
        m[n] = min(x, y);
        if(m[n]<LLONG_MAX) ++m[n];
        return m[n];
    };
    ll ans = solve(1);
    if(ans<LLONG_MAX) cout << ans << endl;
    else cout << -1 << endl;
}
