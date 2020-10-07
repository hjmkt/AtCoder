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
    ll L;
    cin >> L;
    vll b(L);
    rep(i, L){
        cin >> b[i];
    }
    ll t = 0;
    rep(i, L-1){
        t ^= b[i];
    }
    if(t==b[L-1]){
        t = 0;
        cout << t << endl;
        rep(i, L-1){
            t = t^b[i];
            cout << t << endl;
        }
    }
    else{
        cout << -1 << endl;
    }
}
