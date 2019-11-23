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
    ll N, K;
    cin >> N >> K;
    vll a(N);
    ll s = 0;
    rep(i, N){
        cin >> a[i];
        s += a[i];
    }
    vll rs;
    REP(i, 1, sqrt(s)+1){
        if(s%i==0){
            rs.push_back(i);
                rs.push_back(s/i);
        }
    }
    ll m = 0;
    for(ll r : rs){
        ll rem = K*2;
        rep(i, N){
            rem -= min(abs(a[i]/r*r-a[i]), abs(a[i]/r*(r+1)-a[i]));
            if(rem<0) break;
        }
        if(rem>=0){
            if(m<r){
                m = r;
            }
        }
    }
    cout << m << endl;
}
