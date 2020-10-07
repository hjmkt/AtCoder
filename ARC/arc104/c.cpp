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
    vll A(N), B(N);
    rep(i, N) cin >> A[i] >> B[i];

    vll t(2*N+1, 0);
    rep(i, N){
        if((A[i]>0&&t[A[i]]!=0)||(B[i]>0&&t[B[i]]!=0)||(B[i]>0&&A[i]>=B[i])){
            cout << "No" << endl;
            return 0;
        }
        if(A[i]>0&&B[i]>0){
            t[A[i]] = B[i];
            t[B[i]] = -A[i];
        }
        else if(A[i]>0) t[A[i]] = LLONG_MAX;
        else if(B[i]>0) t[B[i]] = LLONG_MIN;
    }

    vll dp(N, 0);
    irep(i, N){
        rep(j, N-i){
            bool possible = true;
            rep(k, j+1){
                ll a = i*2+k+1;
                ll b = i*2+k+1+j+1;
                if(!(
                    (t[a]==LLONG_MAX||t[a]==b||t[a]==0) &&
                    (t[b]==LLONG_MIN||t[b]==-a||t[b]==0) &&
                    (t[a]!=LLONG_MAX||t[b]!=LLONG_MIN)
                )){
                    possible = false;
                    break;
                }
            }
            if(!possible) continue;
            ll next = i+j+1;
            if(next==N) dp[i] = 1;
            else dp[i] = dp[next];
            if(dp[i]) break;
        }
    }
    if(dp[0]) cout << "Yes" << endl;
    else cout << "No" << endl;
}
