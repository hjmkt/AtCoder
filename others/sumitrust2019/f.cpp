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
    ll t[2], a[2], b[2];
    cin >> t[0] >> t[1];
    cin >> a[0] >> a[1];
    cin >> b[0] >> b[1];

    ll x[2], y[2];
    rep(i, 2){
        x[i] = a[i]*t[i];
        y[i] = b[i]*t[i];
    }
    
    if(x[0]+x[1]==y[0]+y[1]){
        cout << "infinity" << endl;
    }
    else{
        if(x[0]+x[1]<y[0]+y[1]) swap(x, y);
        if(x[0]>y[0]) cout << 0 << endl;
        else{
            ll d = x[0]+x[1] - (y[0]+y[1]);
            ll c = (y[0]-x[0]-1) / d;
            c = c*2 + 1;
            if((y[0]-x[0])%d==0) ++c;
            cout << c << endl;
        }
    }
}
