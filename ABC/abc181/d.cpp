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

    string S;
    cin >> S;

    vll d(10, 0);
    rep(i, S.length()){
        ++d[S[i]-'0'];
    }
    vll t;
    REP(i, 1, 10){
        rep(j, min(3ll, d[i])){
            t.push_back(i);
        }
    }
    bool ok = false;
    rep(i, t.size()){
        if(t.size()<2){
            if(t[i]%8==0) ok = true;
            continue;
        }
        rep(j, t.size()){
            if(i==j) continue;
            if(t.size()<3){
                ll n = t[i]*10 + t[j];
                if(n%8==0){
                    ok = true;
                    break;
                }
                continue;
            }
            rep(k, t.size()){
                if(i==k||j==k) continue;
                ll n = t[i]*100 + t[j]*10 + t[k];
                if(n%8==0){
                    ok = true;
                    break;
                }
            }
            if(ok) break;
        }
        if(ok) break;
    }
    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;
}
