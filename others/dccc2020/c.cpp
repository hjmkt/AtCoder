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

int main(){
    cout << setprecision(20);
    ll h, w, k;
    cin >> h >> w >> k;
    vector<string> s(h);
    rep(i, h){
        cin >> s[i];
    }

    vvll a(h, vll(w, 0));
    ll count = 1;
    rep(i, h){
        rep(j, w){
            if(s[i][j]=='#'){
                ll left = j;
                ll right = j;
                while(left>0){
                    if(a[i][left-1]==0 && s[i][left-1]=='.') --left;
                    else break;
                }
                while(right<w-1){
                    if(a[i][right+1]==0 && s[i][right+1]=='.') ++right;
                    else break;
                }
                ll top = i;
                ll bottom = i;
                while(top>0){
                    bool f = true;
                    REP(k, left, right+1){
                        if(a[top-1][k]>0 || s[top-1][k]=='#'){
                            f = false;
                            break;
                        }
                    }
                    if(f) --top;
                    else break;
                }
                while(bottom<h-1){
                    bool f = true;
                    REP(k, left, right+1){
                        if(a[bottom+1][k]>0 || s[bottom+1][k]=='#'){
                            f = false;
                            break;
                        }
                    }
                    if(f) ++bottom;
                    else break;
                }
                REP(k, top, bottom+1){
                    REP(l, left, right+1){
                        a[k][l] = count;
                    }
                }
                ++count;
            }
        }
    }

    rep(i, h){
        rep(j, w){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}
