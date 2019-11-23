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
    ll x, y;
    cin >> x >> y;

    ll s = 0;
    if(x<=3) s += 400000 - x*100000;
    if(y<=3) s += 400000 - y*100000;
    if(x==1&&y==1) s += 400000;

    cout << s << endl;
}
