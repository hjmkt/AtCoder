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

    vvll pm(5001, vll(5001, 0));
    rep(i, 5001){
        pm[i][0] = 1;
        rep(j, 5000){
            pm[i][j+1] = (pm[i][j]*i%998244353+998244353) % 998244353;
        }
    }

    ll ans = 0;
    REP(n, 1, N+1){
        REP(m, 1, M+1){
            if(n<=N-2){
                ll t = (m-1)*(m-1)*pm[M][N-n-2]%998244353*(N-n-1)%998244353;
                t = (t + 2*(m-1)*pm[M][N-n-1]%998244353) % 998244353;
                if(m<M){
                    t = t*(pm[M-m+1][n]-pm[M-m][n]) % 998244353;
                }
                ans = (ans+t) % 998244353;
            }
            else if(n<=N-1){
                ll t = 2*(m-1) % 998244353;
                if(m<M){
                    t = t*(pm[M-m+1][n]-pm[M-m][n]) % 998244353;
                }
                ans = (ans+t) % 998244353;
            }
            else{
                ll t = 1;
                if(m<M){
                    t = t*(pm[M-m+1][n]-pm[M-m][n]) % 998244353;
                }
                ans = (ans+t) % 998244353;
            }
        }
    }
    ans = (ans+998244353) % 998244353;
    cout << ans << endl;
}
