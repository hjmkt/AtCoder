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

    ll N, L, R;
    cin >> N >> L >> R;

    vll ones;
    ll t = N;
    ll b = 0;
    while(t>0){
        if(t&1) ones.push_back(b);
        t >>= 1; 
        ++b;
    }

    ll l = 0, r = 0;
    for(ll b : ones){
        ll s = 1ll << b;
        if(R>=s*2-1) r += s;
        else if(R>=s) r += R - s + 1;
        if(L-1>=s*2-1) l += s;
        else if(L-1>=s) l += L-1 - s + 1;
    }
    ll ans = r - l;
    cout << ans << endl;
}
