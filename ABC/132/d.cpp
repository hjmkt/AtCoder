#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;

#define REP(i, x, n) for(ll i=x; i<(ll)n; ++i)
#define rep(i, n) REP(i, 0, n)
#define all(v) v.begin(), v.end()

ll comb(ll n, ll m){
    static vvll d(2001, vll(2001, 0));
    if(n==m||n==0||m==0) return 1;
    if(d[n][m]>0) return d[n][m];
    if(n<m) return 0;
    ll a = comb(n-1, m-1);
    ll b = comb(n-1, m);
    ll res = (a+b) % 1000000007;
    d[n][m] = res;
    return res;
}

int main(){
    ll N, K;
    cin >> N >> K;
    REP(i, 1, K+1){
        ll a = (comb(N-K+1, i) * comb(K-1, i-1)) % 1000000007;
        cout << a << endl;
    }
}
