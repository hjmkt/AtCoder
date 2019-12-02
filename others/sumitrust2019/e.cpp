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
    vll a(n);
    rep(i, n) cin >> a[i];

    ll count = 1;
    //ll color = 0;
    ll c[3] = {};
    rep(i, n){
        ll cands = 0;
        rep(j, 3) if(a[i]==c[j]) ++cands;
        count = (count*cands) % 1000000007;
        rep(j, 3){
            if(a[i]==c[j]){
                ++c[j];
                break;
            }
        }
    }
    cout << count << endl;
}
