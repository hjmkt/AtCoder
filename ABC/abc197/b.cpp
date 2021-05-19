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

    ll H, W, X, Y;
    cin >> H >> W >> X >> Y;
    vector<string> S(H);
    rep(i, H) cin >> S[i];

    ll count = 1;
    irep(x, X-1){
        if(S[x][Y-1]=='#') break;
        ++count;
    }
    REP(x, X, H){
        if(S[x][Y-1]=='#') break;
        ++count;
    }
    irep(y, Y-1){
        if(S[X-1][y]=='#') break;
        ++count;
    }
    REP(y, Y, W){
        if(S[X-1][y]=='#') break;
        ++count;
    }
    cout << count << endl;
}
