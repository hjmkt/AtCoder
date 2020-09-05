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

    ll N;
    cin >> N;
    vll A(N+1);
    rep(i, N+1) cin >> A[i];

    vll s(N+1, 0);
    s[0] = 1;
    ll total = 0;
    rep(d, N+1){
        if(A[d]>s[d]){
            cout << -1 << endl;
            return 0;
        }
        total += s[d];
        ll r = s[d] - A[d];
        if(d<N){
            s[d+1] = 2*r;
        }
        else{
            if(s[d]==A[d]) cout << total << endl;
            else if(s[d]<A[d]) cout << -1 << endl;
            else{
                ll p = s[d] - A[d];
                if(p<=s[d]/2){
                    cout << total-p << endl;
                    return 0;
                }
                p -= s[d]/2;
                total -= s[d]/2;
                ll m = s[d]/2;
                irep(b, N){
                    ll t = m/2;
                    m = min(s[b]/2, m);
                    if(p<=m){
                        cout << total - (N-b+1)*p << endl;
                        return 0;
                    }
                    p -= m;
                    total -= (N-b+1)*m;
                    m = t;
                }
                cout << -1 << endl;
            }
        }
    }
}
