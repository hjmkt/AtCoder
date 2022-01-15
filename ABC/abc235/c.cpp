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

    ll N, Q;
    cin >> N >> Q;
    vll a(N);
    rep(i, N) cin >> a[i];
    vll x(Q), k(Q);
    rep(i, Q) cin >> x[i] >> k[i];

    map<ll, vll> m;
    rep(i, N){
        m[a[i]].push_back(i+1);
    }
    rep(i, Q){
        if(m.find(x[i])!=m.end()){
            if(m[x[i]].size()>=k[i]){
                cout << m[x[i]][k[i]-1] << endl;
            }
            else{
                cout << -1 << endl;
            }
        }
        else{
            cout << -1 << endl;
        }
    }
}
