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

    ll H, W;
    cin >> H >> W;
    vector<string> S(H);
    rep(i, H) cin >> S[i];

    vector<string> s(H+2);
    s[0] = string(W+2, '.');
    s[H+1] = string(W+2, '.');
    REP(i, 1, H+1) s[i] = "." + S[i-1] + ".";

    ll count = 0;
    REP(h, 1, H+1) REP(w, 1, W+1){
        REP(th, h-1, h+1){
            REP(tw, w-1, w+1){
                ll tmp = 0;
                if(s[th][tw]!=s[h][w]) ++tmp;
                if(s[th][tw+1]!=s[h][w]) ++tmp;
                if(s[th+1][tw]!=s[h][w]) ++tmp;
                if(s[th+1][tw+1]!=s[h][w]) ++tmp;
                if(tmp==3) ++count;
            }
        }
    }
    cout << count << endl;
}
