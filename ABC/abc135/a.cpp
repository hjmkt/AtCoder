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
    ll A, B;
    cin >> A >> B;
    if((A-B)%2==0){
        if(A==B){
            cout << 0 << endl;
        }
        else{
            ll k = (A+B) / 2;
            cout << k << endl;
        }
    }
    else{
        cout << "IMPOSSIBLE" << endl;
    }
}
