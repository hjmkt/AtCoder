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

    ll K;
    cin >> K;

    ll count = 0;
    ll t = 0;
    REP(i, 1, K+1){
        if(i*(i+1)*(i+2)>K) break;
        REP(j, i+1, K+1){
            if(i*j*(j+1)>K) break;
            REP(k, j+1, K+1){
                if(i*j*k>K) break;
                ++t;
            }
        }
    }
    count += 6*t;

    t = 0;
    REP(i, 1, K+1){
        if(i*i>K) break;
        REP(j, 1, K+1){
            if(i*i*j>K) break;
            if(i!=j){
                ++t;
            }
        }
    }
    count += 3*t;

    t = 0;
    REP(i, 1, K+1){
        if(i*i*i>K) break;
        ++t;
    }
    count += t;

    cout << count << endl;
}
