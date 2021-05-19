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

    ll N;
    cin >> N;

    string s = to_string(N);
    bool ok = false;
    string t = s;
    rep(i, 10){
        bool r = true;
        rep(j, t.length()/2){
            if(t[j]!=t[t.length()-j-1]){
                r = false;
                break;
            }
        }
        if(r){
            cout << "Yes" << endl;
            return 0;
        }
        t = "0" + t;
    }
    cout << "No" << endl;
}
