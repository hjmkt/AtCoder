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

    ll N, A, B, C;
    cin >> N >> A >> B >> C;

    ll m = LLONG_MAX;
    rep(a, 10000){
        rep(b, 10000-a){
            ll p = N - a*A - b*B;
            if(p<0) break;
            if(p%C!=0) continue;
            ll c = p/C;
            ll n = a + b + c;
            m = min(m, n);
        }
    }
    cout << m << endl;
}
