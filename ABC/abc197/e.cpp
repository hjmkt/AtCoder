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

    ll N;
    cin >> N;
    vll X(N), C(N);
    rep(i, N) cin >> X[i] >> C[i];

    map<ll, set<ll>> m;
    rep(i, N) m[C[i]].insert(X[i]);
    vector<set<ll>> v;
    for(auto p : m){
        v.push_back(p.second);
    }
    ll colors = v.size();

    vvll dp(colors, vll(2, 0));
    dp[colors-1][0] = abs(*(m.rbegin()->second.begin()));
    dp[colors-1][1] = abs(*(m.rbegin()->second.rbegin()));
    irep(i, colors-1){
        dp[i][0] = *v[i+1].rbegin()<*v[i].begin()? abs(*v[i].begin()-*v[i+1].begin()) + dp[i+1][0] :
            *v[i+1].begin()>*v[i].begin()? abs(*v[i].begin()-*v[i+1].rbegin()) + dp[i+1][1] : min(
            abs(*v[i+1].rbegin()-*v[i].begin()) + *v[i+1].rbegin()-*v[i+1].begin() + dp[i+1][0],
            abs(*v[i+1].begin()-*v[i].begin()) + *v[i+1].rbegin()-*v[i+1].begin() + dp[i+1][1]
        );
        dp[i][1] = *v[i+1].rbegin()<*v[i].rbegin()? abs(*v[i].rbegin()-*v[i+1].begin()) + dp[i+1][0] :
            *v[i+1].begin()>*v[i].rbegin()? abs(*v[i].rbegin()-*v[i+1].rbegin()) + dp[i+1][1] : min(
            abs(*v[i+1].rbegin()-*v[i].rbegin()) + *v[i+1].rbegin()-*v[i+1].begin() + dp[i+1][0],
            abs(*v[i+1].begin()-*v[i].rbegin()) + *v[i+1].rbegin()-*v[i+1].begin() + dp[i+1][1]
        );
    }
    ll ans = *v[0].rbegin()<0? abs(*v[0].begin())+dp[0][0] :
        *v[0].begin()>0? abs(*v[0].rbegin())+dp[0][1] : min(
        dp[0][1] + abs(*v[0].begin()) + *v[0].rbegin()-*v[0].begin(),
        dp[0][0] + abs(*v[0].rbegin()) + *v[0].rbegin()-*v[0].begin()
    );
    cout << ans << endl;
}
