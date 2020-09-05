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

    vll t = {0, 0, 1, 0};
    rep(i, n-1){
        t[3] = (t[0]+t[1]+t[2]) % 10007;
        t[0] = t[1];
        t[1] = t[2];
        t[2] = t[3];
    }
    cout << t[0] << endl;
}
