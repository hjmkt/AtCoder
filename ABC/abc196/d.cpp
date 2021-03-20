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

    ll H, W, A, B;
    cin >> H >> W >> A >> B;

    function<ll(ll, ll, ll)> solve = [&](ll r, ll a, ll b){
        if(a==0 && b==0) return 1ll;
        ll t = 0;
        bool found = false;
        rep(h, H){
            rep(w, W){
                if(((r>>(h*W+w))&1)>0) continue;
                if(b>0){
                    t += solve(r|(1ll<<(h*W+w)), a, b-1);
                    found = true;
                }
                if(a>0){
                    if(h<H-1){
                        if(((r>>((h+1)*W+w))&1)==0){
                            found = true;
                            t += solve(r|(1ll<<(h*W+w))|(1ll<<((h+1)*W+w)), a-1, b);
                        }
                    }
                    if(w<W-1){
                        if(((r>>(h*W+w+1)&1)==0)){
                            found = true;
                            t += solve(r|(1ll<<(h*W+w))|(1ll<<(h*W+w+1)), a-1, b);
                        }
                    }
                }
                if(found) break;
            }
            if(found) break;
        }
        return t;
    };
    ll ans = solve(0, A, B);
    cout << ans << endl;
}
