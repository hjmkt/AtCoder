#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
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
    vll X(N);
    rep(i, N) cin >> X[i];

    vll ps = {2, 3, 5, 7, 11, 13, 17, 19, 23, 27, 29, 31, 37, 41, 43, 47};
    ll m = LLONG_MAX;
    rep(bs, (1ll<<16)){
        bool ok = true;
        rep(i, N){
            bool t = false;
            rep(j, 16){
                if((bs>>j)&1){
                    if(X[i]%ps[j]==0){
                        t = true;
                        break;
                    }
                }
            }
            if(!t){
                ok = false;
                break;
            }
        }
        if(ok){
            ull v = 1;
            rep(j, 16){
                if((bs>>j)&1){
                    v *= ps[j];
                }
            }
            m = min((ull)m, v);
        }
    }
    cout << m << endl;
}
