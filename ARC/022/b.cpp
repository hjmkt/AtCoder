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
    ll n;
    cin >> n;
    vll a(n);
    rep(i, n){
        cin >> a[i];
    }
    if(n==1){
        cout << 1 << endl;
        return 0;
    }

    vll c(100001, 0);
    ll left = 0;
    ll right = 0;
    c[a[left]] = 1;
    ll m = 1;
    while(right<n-1){
        if(c[a[right+1]]){
            while(a[left]!=a[right+1]){
                c[a[left]] = 0;
                ++left;
            }
            ++left;
            ++right;
        }
        else{
            ++right;
            c[a[right]] = 1;
        }
        ll count = right-left+1;
        if(count>m) m = count;
    }
    cout << m << endl;
}
