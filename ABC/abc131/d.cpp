#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;

#define REP(i, x, n) for(ll i=x; i<(ll)n; ++i)
#define rep(i, n) REP(i, 0, n)
#define all(v) v.begin(), v.end()

int main(){
    ll n;
    cin >> n;
    vector<pair<ll, ll>> ab(n);
    rep(i, n) cin >> ab[i].first >> ab[i].second;
    sort(ab.begin(), ab.end(), [](auto l, auto r){
        return l.second < r.second;
    });
    ll t = 0;
    rep(i, n){
        t += ab[i].first;
        if(t>ab[i].second){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}
