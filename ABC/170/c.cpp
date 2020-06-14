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
#define vvprint(vv) for(auto v:vv)vprint(v);

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);

    ll X, N;
    cin >> X >> N;
    vll p(N);
    rep(i, N) cin >> p[i];
    ll md = 101;
    ll m = -1;
    REP(i, 0, 102){
        if(find(all(p), i)==p.end()){
            ll d = abs(i-X);
            if(d<md){
                md = d;
                m = i;
            }
        }
    }
    cout << m << endl;
}
