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

    vector<char> S(3), T(3);
    rep(i, 3) cin >> S[i];
    rep(i, 3) cin >> T[i];
    if(S[0]==T[0]){
        if(S[1]==T[1]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    else{
        if(S[1]==T[1]) cout << "No" << endl;
        else if(S[2]==T[2]) cout << "No" << endl;
        else cout << "Yes" << endl;
    }
}
