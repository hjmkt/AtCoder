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
    vll l(n);
    rep(i, n) cin >> l[i];
    sort(all(l));

    auto sum = [&](ll left, ll right, ll m){
        auto lb = lower_bound(l.begin()+m, l.end(), left+1);
        auto ub = lower_bound(l.begin()+m, l.end(), right);
        if(lb==l.end() || lb>=ub) return 0ll;
        else return (ll)(ub-lb);
    };

    ll count = 0;
    rep(i, n){
        REP(j, i+1, n){
            count += sum(abs(l[i]-l[j]), l[i]+l[j], j+1);
        }
    }
    cout << count << endl;
}
