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

    ll N, X, M;
    cin >> N >> X >> M;

    unordered_map<ll, ll> m;
    vll a(M);
    a[0] = X;
    m[a[0]] = 0;

    ll last = 0;
    ll back = 0;
    REP(i, 1, M){
        a[i] = (a[i-1]*a[i-1]) % M;
        if(m.find(a[i])!=m.end()){
            back = m[a[i]];
            break;
        }
        m[a[i]] = i;
        ++last;
    }
    if(N<=last+1){
        ll s = 0;
        rep(i, N) s += a[i];
        cout << s << endl;
    }
    else{
        ll s = 0, t = 0;
        rep(i, last+1) s += a[i];
        REP(i, back, last+1) t += a[i];
        ll r = N - last - 1;
        ll total = s;
        total += t*(r/(last+1-back));
        r %= last+1-back;
        REP(i, back, back+r) total += a[i];
        cout << total << endl;
    }
}
