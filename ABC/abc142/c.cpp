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
    vector<pair<ll, ll>> ia(n);
    rep(i, n){
        ia[i].first = i+1;
        cin >> ia[i].second;
    }

    sort(all(ia), [](pair<ll, ll> l, pair<ll, ll> r){ return l.second<r.second; });
    rep(i, n){
        cout << ia[i].first << " ";
    }
    cout << endl;
}
