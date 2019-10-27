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
    ll n, k;
    cin >> n >> k;
    vll a(n), f(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> f[i];
    
    sort(all(a));
    sort(all(f), greater<ll>());

    ll left=0, right=1000000000000;
    while(left<right){
        ll mid = (left+right)/2;
        ll count = 0;
        bool possible = true;
        rep(i, n){
            if(a[i]*f[i]>mid){
                count += a[i] - mid/f[i];
            }
            if(count>k){
                possible = false;
                break;
            }
        }
        if(possible) right = mid;
        else left = mid + 1;
    }
    cout << left << endl;
}
