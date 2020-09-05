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

    ll N, A, B;
    cin >> N >> A >> B;

    vvll dp(N+1, vll(N+1, 0));
    if(A<B) swap(A, B);
    REP(i, 1, N+1) rep(j, N+1){
        if(j>i) continue;
        if(i==0){
            dp[i][j] = 0;
            continue;
        }
        if(j==0){
            ll count = 0;
            rep(k, i-B+1){
                count = (count+dp[i-k-1][B]) % 1000000007;
            }
            dp[i][j] = count;
        }
        else{
            ll count = 0;
            rep(k, max(1, j-A+1)){
                if(k+A>N) break;
                if(k+A>=j) count = (count+dp[i-k-1][0]) % 1000000007;
                else{
                    count = (count+dp[]) % 1000000007;
                }
            }
        }
    }
}
