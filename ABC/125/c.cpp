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

ll gcd(ll n, ll m){
    while(true){
        if(n<m) swap(n, m);
        if(!m) break;
        n %= m;
    }
    return n;
}

int main(){
    ll n;
    cin >> n;
    vll a(n);
    rep(i, n){
        cin >> a[i];
    }
    vll l(n);
    l[0] = a[0];
    REP(i, 1, n){
        l[i] = gcd(l[i-1], a[i]);
    }
    vll r(n);
    r[n-1] = a[n-1];
    IREP(i, n-1, 0){
        r[i] = gcd(r[i+1], a[i]);
    }
    ll m = 0;
    rep(i, n){
        ll t = i>0? (i<n-1? gcd(l[i-1], r[i+1]) : l[i-1]) : r[i+1];
        if(t>m) m = t;
    }
    cout << m << endl;
}
