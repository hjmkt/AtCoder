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
    vll s(N);
    rep(i, N) cin >> s[i];

    ll ans = 0;
    REP(i, 1, N/2){
        unordered_set<ll> checked;
        ll t = 0;
        for(ll j=i; j+i<N-1; j+=i){
            if(j==N-1-j || j>N-1-i || N-1-j<i) break;
            if(checked.count(j)>0 || checked.count(N-1-j)>0) break;
            t += s[j] + s[N-1-j];
            ans = max(ans, t);
            checked.insert(j);
            checked.insert(N-1-j);
        }
    }
    cout << ans << endl;
}
