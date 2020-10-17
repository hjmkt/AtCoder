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
    vll x(N);
    rep(i, N) cin >> x[i];

    ll d1 = 0;
    rep(i, N) d1 += abs(x[i]);

    ll t = 0;
    rep(i, N) t += x[i]*x[i];
    double d2 = sqrt((double)t);

    ll d3 = 0;
    rep(i, N) d3 = max(d3, abs(x[i]));

    cout << d1 << endl;
    cout << d2 << endl;
    cout << d3 << endl;
}
