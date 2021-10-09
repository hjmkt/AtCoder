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

    ll N, K;
    cin >> N >> K;
    string S;
    cin >> S;

    string a = "";
    rep(i, S.length()){
        if(a.length()>=K) break;
        char c = 127;
        ll idx = -1;
        REP(j, i, N-K+a.length()+1){
            if(S[j]<c){
                c = S[j];
                idx = j;
            }
        }
        a += c;
        i = idx;
    }
    cout << a << endl;
}
