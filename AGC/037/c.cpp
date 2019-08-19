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
    vll a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];

    priority_queue<pair<ll, ll>> q;
    rep(i, n) q.push({b[i], i});
    ll count = 0;
    while(!q.empty()){
        auto e = q.top();
        q.pop();
        ll c = e.second;
        ll l = (e.second-1+n) % n;
        ll r = (e.second+1) % n;
        if(b[c]>=a[c]+b[l]+b[r]){
            count += (b[c]-a[c])/(b[l]+b[r]);
            b[c] = a[c] + (b[c]-a[c])%(b[l]+b[r]);
            if(b[c]==a[c]) continue;
        }
        else if(b[c]==a[c]) continue;
        else{
            cout << -1 << endl;
            return 0;
        }
        q.push({b[c], c});
    }
    cout << count << endl;
}
