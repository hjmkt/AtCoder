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
    ll S;
    cin >> S;
    ll n = sqrt(S);
    if(n*n<S) ++n;
    ll xy = n*n - S;
    ll m = 1;
    for(ll d=sqrt(xy); d>=1; --d){
        if(xy%d==0){
            m = d;
            break;
        }
    }
    ll x = m;
    ll y = xy / m;
    cout << "0 0 " << x << " " << n << " " << n << " " << y << endl;
}
