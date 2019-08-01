#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;

#define REP(i, x, n) for(ll i=x; i<(ll)n; ++i)
#define rep(i, n) REP(i, 0, n)
#define all(v) v.begin(), v.end()

int main(){
    ll N, L;
    cin >> N >> L;
    ll m = 1e10;
    ll s = 0;
    ll t = 0;
    REP(i, 1, N+1){
        s += L + i - 1;
    }
    REP(i, 1, N+1){
        ll a = abs(L+i-1);
        if(m>a){
            m = a;
            t = L + i - 1;
        }
    }
    cout << (s-t) << endl;
}
