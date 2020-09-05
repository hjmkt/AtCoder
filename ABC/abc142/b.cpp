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
    vll h(n);
    rep(i, n) cin >> h[i];

    ll count = 0;
    rep(i, n){
        if(h[i]>=k) ++count;
    }
    cout << count << endl;
}
