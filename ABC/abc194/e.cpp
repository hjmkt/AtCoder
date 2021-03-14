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
    vll A(N);
    rep(i, N) cin >> A[i];

    map<ll, ll> m;
    set<ll> s;
    rep(i, N+1){
        s.insert(i);
    }
    rep(i, M){
        ++m[A[i]];
        s.erase(A[i]);
    }
    ll ans = *s.begin();
    rep(i, N-M){
        --m[A[i]];
        if(m[A[i]]<=0){
            m.erase(A[i]);
            s.insert(A[i]);
        }
        ++m[A[i+M]];
        s.erase(A[i+M]);
        ans = min(ans, *s.begin());
    }
    cout << ans << endl;
}
