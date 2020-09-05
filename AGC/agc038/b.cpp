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
    ll n, k;
    cin >> n >> k;
    vll p(n);
    rep(i, n) cin >> p[i];

    set<ll> s;
    ll st = 0;
    ll last = -1;
    ll st_count = 0;
    rep(i, k){
        s.insert(p[i]);
        if(last<p[i]) ++st;
        else st = 1;
        last = p[i];
        if(st>=k) ++st_count;
    }
    ll count = 1;
    REP(i, k, n){
        if(last<p[i]) ++st;
        else st = 1;
        last = p[i];
        ll pmin = *(s.begin());
        ll pmax = *(s.rbegin());
        if(p[i-k]>pmin || p[i]<pmax){
            if(st<k || st_count==0) ++count;
            if(st>=k) ++st_count;
        }
        s.erase(p[i-k]);
        s.insert(p[i]);
    }
    cout << count << endl;
}

