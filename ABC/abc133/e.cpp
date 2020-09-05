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
    ll N, K;
    cin >> N >> K;
    vector<set<ll>> t(N);
    rep(i, N-1){
        ll a, b;
        cin >> a >> b;
        t[a-1].insert(b-1);
        t[b-1].insert(a-1);
    }
    function<ll(ll, ll, ll)> solve = [&](ll current, ll last, ll last2){
        ll count = last>=0? (K-1-last2) : K;
        ll total = 1;
        ll i = 0;
        for(ll n : t[current]){
            if(n==last) continue;
            total = (total * solve(n, current, last2>=0? (i+1) : i)) % 1000000007;
            ++i;
        }
        return (count*total) % 1000000007;
    };
    cout << solve(0, -1, -1) << endl;
}
