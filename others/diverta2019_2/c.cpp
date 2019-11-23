#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;

#define REP(i, x, n) for(ll i=x; i<(ll)n; ++i)
#define rep(i, x) REP(i, 0, x)
#define all(v) v.begin(), v.end()

int main(){
    ll N;
    cin >> N;
    vll a(N);
    rep(i, N){
        cin >> a[i];
    }
    sort(all(a));
    ll r = N;
    rep(i, N){
        if(a[i]>=0){
            r = i;
            break;
        }
    }
    vector<pair<ll, ll>> s;
    ll c = a[N-1];
    r = max(r, 1ll);
    if(r>=N-1){
        REP(i, 0, N-1){
            s.push_back({c, a[i]});
            c = c - a[i];
        }
    }
    else{
        REP(i, r, N-1){
            s.push_back({a[0], a[i]});
            c = a[0] - a[i];
            a[0] = c;
        }
        c = a[N-1];
        rep(i, r){
            s.push_back({c, a[i]});
            c -= a[i];
        }
    }
    cout << c << endl;
    rep(i, N-1){
        cout << s[i].first << " " << s[i].second << endl;
    }
}
