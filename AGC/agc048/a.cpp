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

    string ac = "atcoder";

    ll T;
    cin >> T;
    REP(t, 1, T+1){
        string S;
        cin >> S;
        bool valid = false;
        rep(i, S.length()){
            if(S[i]!='a') valid = true;
        }
        if(!valid){
            cout << -1 << endl;
            continue;
        }
        if(S>ac) cout << 0 << endl;
        else{
            ll idx = 0;
            while(S[idx]=='a') ++idx;
            ll count = 0;
            irep(i, idx){
                ++count;
                swap(S[i], S[i+1]);
                if(S>ac) break;
            }
            cout << count << endl;
        }
    }
}
