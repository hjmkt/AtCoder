#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;

#define REP(i, n, m) for(ll i=n; i<(ll)m; ++i)
#define IREP(i, n, m) for(ll i=n-1; i>=m; --i)
#define rep(i, n) REP(i, 0, n)
#define irep(i, n) IREP(i, n, 0)
#define all(v) v.begin(), v.end()

int main(){
    ll n, k;
    cin >> n >> k;
    vector<double> r(n);
    rep(i, n) cin >> r[i];
    double c = 0;
    sort(all(r), greater<double>());
    irep(i, k){
        if(c<r[i]) c = (c+r[i]) / 2;
        else break;
    }
    cout << setprecision(10) << c << endl;
}
