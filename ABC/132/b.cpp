#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;

#define REP(i, x, n) for(ll i=x; i<(ll)n; ++i)
#define rep(i, n) REP(i, 0, n)
#define all(v) v.begin(), v.end()

int main(){
    ll n;
    cin >> n;
    vll p(n);
    rep(i, n){
        cin >> p[i];
    }
    ll count = 0;
    REP(i, 1, n-1){
        if((p[i-1]<=p[i]&&p[i]<=p[i+1])||(p[i+1]<=p[i]&&p[i]<=p[i-1])){
            ++count;
        }
    }
    cout << count << endl;
}
