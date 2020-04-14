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
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);

    ll n;
    cin >> n;
    ll d = n/5, r = n%5;

    vll a(6, 0);
    rep(i, 6) a[i] = (d+i)%6 + 1;
    rep(i, r) swap(a[i], a[i+1]);
    rep(i, 6) cout << a[i];
    cout << endl;
}
