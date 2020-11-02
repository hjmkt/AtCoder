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
    vll H(N), W(M);
    rep(i, N) cin >> H[i];
    rep(i, M) cin >> W[i];

    sort(all(H));
    vll s1 = {0}, s2 = {0};
    for(ll i=0; i<N-1; i+=2){
        ll d = abs(H[i+1]-H[i]);
        s1.push_back(s1.back()+d);
    }
    for(ll i=1; i<N-1; i+=2){
        ll d = abs(H[i+1]-H[i]);
        s2.push_back(s2.back()+d);
    }
    ll ans = LONG_MAX;
    rep(i, M){
        auto it = lower_bound(all(H), W[i]);
        ll p = distance(H.begin(), it);
        if(p%2==0){
            ll s = s1[p/2] + abs(H[p]-W[i]) + s2.back()-s2[p/2];
            ans = min(ans, s);
        }
        else{
            ll s = s1[p/2] + abs(H[p-1]-W[i]) + s2.back()-s2[p/2];
            ans = min(ans, s);
        }
    }
    cout << ans << endl;
}
