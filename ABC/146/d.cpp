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

int main(){
    cout << setprecision(20);
    ll n;
    cin >> n;
    vll a(n-1), b(n-1);
    rep(i, n-1) cin >> a[i] >> b[i];

    vector<set<ll>> e(n);
    rep(i, n-1){
        e[a[i]-1].insert(b[i]-1);
        e[b[i]-1].insert(a[i]-1);
    }

    vector<map<ll, ll>> m(n);
    function<ll(ll, ll, ll)> dfs = [&](ll lc, ll lv, ll v){
        ll cc = 0;
        ll colors = 0;
        for(ll nv : e[v]){
            if(nv==lv) continue;
            if(cc==lc) ++cc;
            m[v][nv] = cc;
            m[nv][v] = cc;
            ll tc = dfs(cc, v, nv);
            colors = max(colors, tc);
            colors = max(colors, cc);
            ++cc;
        }
        return colors;
    };
    ll colors = dfs(-1, -1, 0);
    cout << colors+1 << endl;
    rep(i, n-1){
        cout << m[a[i]-1][b[i]-1]+1 << endl;
    }
}
