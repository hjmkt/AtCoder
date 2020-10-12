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

    ll N, K, M;
    cin >> N >> K >> M;
    vvll dp(N+1, vll(N*(N+1)/2*K+1, 0));
    rep(i, N+1) dp[i][0] = 1;
    vvll&& sum = vvll(N+1, vll(1, 0));
    rep(i, N*(N+1)/2*K+1) sum[0].push_back(1);
    rep(i, N){
        vvll t(N+1, vll(1, 0));
        ll offset1 = 0, offset2 = 0, offset3 = 0;
        rep(j, N*(N+1)/2*K+1){
            ll s = sum[offset1][offset2+1] - sum[offset1][max(0ll, offset2-K)];
            s = (s+M) % M;
            dp[i+1][j] = s;
            t[offset3].push_back((t[offset3].back()+s) % M);
            ++offset1;
            ++offset3;
            if(offset1==i+1){
                offset1 = 0;
                ++offset2;
            }
            if(offset3==i+2) offset3 = 0;
        }
        sum = t;
    }
    REP(i, 1, N+1){
        ll s = 0;
        rep(j, N*(N+1)/2*K+1){
            ll d = dp[i-1][j]*dp[N-i][j] % M;
            d = d*(K+1) % M;
            s = (s+d) % M;
        }
        s = ((s-1)+M) % M;
        cout << s << endl;
    }
}
