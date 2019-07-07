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
    ll L, R;
    cin >> L >> R;

    if(R>=L+2018){
        cout << 0 << endl;
    }
    else{
        ll m = 2018;
        REP(i, L, R+1){
            REP(j, i+1, R+1){
                ll t = ((i*j) % 2019 + 2019) % 2019;
                if(t<m) m = t;
            }
        }
        cout << m << endl;
    }
}
