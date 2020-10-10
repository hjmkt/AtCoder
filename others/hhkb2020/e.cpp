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


ll pow_mod(ll n, ll m, ll mod=1000000007){
    ll a = 1;
    while(m>0){
        if(m&1) a = a*n % mod;
        n = n*n % mod;
        m >>= 1;
    }
    return a;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);

    ll H, W;
    cin >> H >> W;
    vector<string> S(H);
    rep(i, H) cin >> S[i];

    ll M = 1000000007;

    vvll hs(H, vll(W, 0)), ws(H, vll(W, 0));

    ll spaces = 0;
    rep(i, H) rep(j, W){
        if(S[i][j]=='.') ++spaces;
    }

    rep(y, H){
        ll count = 0;
        rep(x, W){
            ll start = x;
            if(S[y][x]=='.'){
                ++count;
                while(x+1<W&&S[y][x+1]=='.'){
                    ++count;
                    ++x;
                }
                REP(i, start, x+1){
                    ws[y][i] = count;
                }
            }
            count = 0;
        }
    }
    rep(x, W){
        ll count = 0;
        rep(y, H){
            ll start = y;
            if(S[y][x]=='.'){
                ++count;
                while(y+1<H&&S[y+1][x]=='.'){
                    ++count;
                    ++y;
                }
                REP(i, start, y+1){
                    hs[i][x] = count;
                }
            }
            count = 0;
        }
    }
    ll count = 0;
    rep(i, H) rep(j, W){
        if(S[i][j]=='.'){
            ll n = hs[i][j] + ws[i][j] - 1;
            ll c = pow_mod(2, spaces)-pow_mod(2, spaces-n);
            c = (c%M+M) % M;
            count = (count+c) % M;
        }
    }
    cout << count << endl;
}

