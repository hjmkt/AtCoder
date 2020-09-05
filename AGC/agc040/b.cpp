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
    ll n;
    cin >> n;
    vector<pair<ll, ll>> lr(n);
    rep(i, n){
        cin >> lr[i].first >> lr[i].second;
        --lr[i].first;
        --lr[i].second;
    }
    sort(all(lr), [](pair<ll, ll> x, pair<ll, ll> y){
        if(x.first<y.first) return true;
        else if(x.first==y.first && x.second<y.second) return true;
        else return false;
    });

    ll a = 0;

    // one and the others
    vector<pair<ll, ll>> acc_lr0(n);
    vector<pair<ll, ll>> acc_lr1(n);
    ll l = 0, r = 1000000000-1;
    rep(i, n){
        l = max(l, lr[i].first);
        r = min(r, lr[i].second);
        acc_lr0[i] = {l, r};
    }
    l = 0, r = 1000000000-1;
    irep(i, n){
        l = max(l, lr[i].first);
        r = min(r, lr[i].second);
        acc_lr1[i] = {l, r};
    }
    rep(i, n){
        ll t = lr[i].second - lr[i].first + 1;
        ll l = 0, r = 1000000000-1;
        if(i>0){
            l = max(l, acc_lr0[i-1].first);
            r = min(r, acc_lr0[i-1].second);
        }
        if(i<n-1){
            l = max(l, acc_lr1[i+1].first);
            r = min(r, acc_lr1[i+1].second);
        }
        if(l<=r) t += r - l + 1;
        a = max(a, t);
    }

    // otherwise
    REP(i, 1, n-2){
        ll l0 = acc_lr0[i].first, r0 = acc_lr0[i].second;
        ll l1 = acc_lr1[i+1].first, r1 = acc_lr1[i+1].second;
        ll t = 0;
        if(l0<=r0) t += r0 - l0 + 1;
        if(l1<=r1) t += r1 - l1 + 1;
        a = max(a, t);
    }

    cout << a << endl;
}
