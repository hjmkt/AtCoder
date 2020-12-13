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

    ll N, M;
    cin >> N >> M;
    vll A(M);
    rep(i, M) cin >> A[i];

    if(M==0){
        cout << 1 << endl;
        return 0;
    }

    set<ll> s, d;
    rep(i, M) s.insert(A[i]);
    s.insert(N+1);
    ll t = 0;
    for(ll e : s){
        if(e-t>1) d.insert(e-t-1);
        t = e;
    }
    if(d.size()==0){
        cout << 0 << endl;
        return 0;
    }
    vll v;
    for(ll e : d) v.push_back(e);
    ll m = v[0];
    rep(i, v.size()-1){
        m = min(m, v[i+1]);
    }
    ll a = 0;
    t = 0;
    for(ll e : s){
        if(e-t>1) a += (e-t-1+m-1) / m;
        t = e;
    }
    cout << a << endl;
}
