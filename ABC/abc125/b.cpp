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
    ll n;
    cin >> n;
    vll v(n), c(n);
    rep(i, n){
        cin >> v[i];
    }
    rep(i, n){
        cin >> c[i];
    }
    ll total = 0;
    rep(i, n){
        if(v[i]>c[i]){
            total += v[i] - c[i];
        }
    }
    cout << total << endl;
}
