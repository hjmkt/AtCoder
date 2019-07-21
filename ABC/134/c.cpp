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
    ll N;
    cin >> N;
    vll a(N);
    rep(i, N){
        cin >> a[i];
    }
    ll f = 0, s = 0;
    rep(i, N){
        if(a[i]>f){
            s = f;
            f = a[i];
        }
        else if(a[i]>s){
            s = a[i];
        }
    }
    rep(i, N){
        if(a[i]==f) cout << s << endl;
        else cout << f << endl;
    }
}
