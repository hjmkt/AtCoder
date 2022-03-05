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

    ll T;
    cin >> T;
    rep(_, T){
        ll N;
        cin >> N;
        string S;
        cin >> S;
        ll ans = 0;
        ll a = 0;
        rep(i, (N+1)/2){
            if(i==(N+1)/2-1){
                ll d = S[i] - 'A';
                ans = (a*26+d) % 998244353;
            }
            else{
                ll d = S[i] - 'A';
                if(a==0){
                    if(d>0) a = d;
                }
                else{
                    a = (a*26+d) % 998244353;
                }
            }
        }
        bool p = true;
        rep(i, N/2){
            if(S[N/2-i-1]<S[(N+1)/2+i]){
                break;
            }
            else if(S[N/2-i-1]>S[(N+1)/2+i]){
                p = false;
                break;
            }
        }
        if(p) ans = (ans+1) % 998244353;
        cout << ans << endl;
    }
}
