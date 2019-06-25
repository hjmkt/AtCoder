#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;

#define REP(i, x, n) for(ll i=x; i<(ll)n; ++i)
#define rep(i, n) REP(i, 0, n)
#define all(v) v.begin(), v.end()

int main(){
    ll n, c;
    cin >> n >> c;
    vll a(n);
    rep(i, n){
        cin >> a[i];
    }
    vector<pair<ll, ll>> f(10, {0, 0});
    vector<pair<ll, ll>> s(10, {0, 0});
    rep(i, 10){
        f[i].first = i;
        s[i].first = i;
    }
    rep(i, n){
        if(i%2==0) ++f[a[i]-1].second;
        else ++s[a[i]-1].second;
    }
    sort(f.begin(), f.end(), [](auto l, auto r){ return l.second > r.second; });
    sort(s.begin(), s.end(), [](auto l, auto r){ return l.second > r.second; });
    ll m = 0;
    if(f[0].first==s[0].first){
        m = max(f[0].second+s[1].second, f[1].second+s[0].second);
        m = n - m;
    }
    else{
        m = f[0].second + s[0].second;
        m = n - m;
    }
    cout << (m*c) << endl;
}
