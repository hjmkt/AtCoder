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
    vector<string> S(N);
    rep(n, N) cin >> S[n];

    unordered_set<string> s1, s2;
    rep(n, N){
        string t = S[n];
        if(t[0]=='!'){
            t = t.substr(1);
            if(s2.count(t)>0){
                cout << t << endl;
                return 0;
            }
            s1.insert(t);
        }
        else{
            if(s1.count(t)>0){
                cout << t << endl;
                return 0;
            }
            s2.insert(t);
        }
    }
    cout << "satisfiable" << endl;
}
