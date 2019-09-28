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
    ll a, b;
    cin >> a >> b;

    ll gcd_ab = gcd(a, b);
    set<ll> s;
    ll n = gcd_ab;
    REP(i, 2, sqrt(gcd_ab)+2){
        while(n%i==0){
            s.insert(i);
            n /= i;
        }
    }
    s.insert(1);
    s.insert(n);
    ll count = s.size();
    cout << count << endl;
}
