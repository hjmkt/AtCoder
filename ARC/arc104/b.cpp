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
    string S;
    cin >> N >> S;

    vll a(N+1), t(N+1), c(N+1), g(N+1);
    rep(i, N){
        a[i+1] = S[i]=='A'? (a[i]+1) : a[i];
        t[i+1] = S[i]=='T'? (t[i]+1) : t[i];
        c[i+1] = S[i]=='C'? (c[i]+1) : c[i];
        g[i+1] = S[i]=='G'? (g[i]+1) : g[i];
    }
    ll count = 0;
    REP(i, 1, N+1){
        rep(j, i){
            if(a[i]-a[j]==t[i]-t[j] && c[i]-c[j]==g[i]-g[j]) ++count;
        }
    }
    cout << count << endl;
}
