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

    vector<string> c(4, "    ");
    rep(i, 4) rep(j, 4) cin >> c[i][j];
    rep(i, 2) swap(c[i], c[3-i]);
    rep(i, 4) rep(j, 2) swap(c[i][j], c[i][3-j]);
    rep(i, 4){
        rep(j, 4) cout << c[i][j] << ' ';
        cout << endl;
    }
}
