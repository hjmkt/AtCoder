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

    vll t(26, 0);
    ++t[S[S.length()-1]-'a'];
    ++t[S[S.length()-2]-'a'];
    ll ans = 0;
    irep(i, S.length()-2){
        ++t[S[i]-'a'];
        if(S[i]==S[i+1]&&S[i]!=S[i+2]){
            ans += S.length()-i - t[S[i]-'a'];
            rep(j, 26){
                if(j==S[i]-'a') t[j] = S.length()-i;
                else t[j] = 0;
            }
        }
    }
    cout << ans << endl;
}
