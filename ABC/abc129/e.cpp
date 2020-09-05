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
    string L;
    cin >> L;

    vll ms(L.length()+1, 0);
    ll n = 1;
    rep(i, L.length()+1){
        ms[i] = n;
        n = (n*3) % 1000000007;
    }

    function<ll(ll n)> f = [&](ll n){
        if(n>=L.length()) return 1ll;
        ll count = 0;
        if(L[n]=='1'){
            ll r = (ll)L.length() - n - 1;
            count += ms[r];
            count = (count + 2*f(n+1)) % 1000000007;
        }
        else{
            count = (count + f(n+1)) % 1000000007;
        }
        return count;
    };

    cout << f(0) << endl;
}
