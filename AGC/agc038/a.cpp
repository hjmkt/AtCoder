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
    ll h, w, a, b;
    cin >> h >> w >> a >> b;

    rep(i, b){
        rep(j, a) cout << 0;
        rep(j, w-a) cout << 1;
        cout << endl;
    }
    rep(i, h-b){
        rep(j, a) cout << 1;
        rep(j, w-a) cout << 0;
        cout << endl;
    }
}
