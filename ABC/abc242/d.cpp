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
    ll Q;
    cin >> Q;
    vll t(Q), k(Q);
    rep(i, Q) cin >> t[i] >> k[i];

    rep(i, Q){
        ll a = t[i];
        ll b = k[i] - 1;
        ll offset = 0;
        while(true){
            if(b==0){
                ll r = ((ll)(S[0]-'A') + a + offset) % 3;
                char ans = (char)r + 'A';
                cout << ans << endl;
                break;
            }
            else if(a==0){
                ll r = ((ll)(S[b]-'A') + offset) % 3;
                char ans = (char)r + 'A';
                cout << ans << endl;
                break;
            }
            offset = (offset+b%2+1)%3;
            b /= 2;
            --a;
        }
    }
}
