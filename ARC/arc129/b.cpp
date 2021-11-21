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
#define vprint(v) for(auto e:v){cout<<e<<" ";};cout<<endl;
#define vvprint(vv) for(auto v:vv){vprint(v)};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);

    ll N;
    cin >> N;
    vll L(N), R(N);
    rep(i, N) cin >> L[i] >> R[i];

    set<ll> ls, rs;
    rep(i, N){
        ls.insert(L[i]);
        rs.insert(R[i]);
        ll r_min = *rs.begin();
        ll l_max = *ls.rbegin();
        if(r_min>=l_max) cout << 0 << endl;
        else{
            ll m = (r_min+l_max) / 2;
            ll a = max(m-r_min, l_max-m);
            cout << a << endl;
        }
    }
}
