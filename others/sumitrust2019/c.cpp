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
    ll x;
    cin >> x;

    rep(i, x/100+1)
    rep(j, 2+1)
    rep(k, 2+1)
    rep(l, 5+1)
    rep(m, 5+1)
    rep(n, 20+1){
        if(100*i+101*j+102*k+103*l+104*m+105*n==x){
            cout << 1 << endl;
            return 0;
        }
    }
    cout << 0 << endl;
}
