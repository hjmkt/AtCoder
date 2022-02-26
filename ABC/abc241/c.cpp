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
    rep(i, N) cin >> S[i];

    rep(i, N){
        rep(j, N-5){
            ll count = 0;
            rep(k, 6){
                if(S[i][j+k]=='#') ++count;
            }
            if(count>=4){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    rep(i, N-5){
        rep(j, N){
            ll count = 0;
            rep(k, 6){
                if(S[i+k][j]=='#') ++count;
            }
            if(count>=4){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    rep(i, N-5){
        rep(j, N-5){
            ll count = 0;
            rep(k, 6){
                if(S[i+k][j+k]=='#') ++count;
            }
            if(count>=4){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    rep(i, N-5){
        rep(j, N-5){
            ll count = 0;
            rep(k, 6){
                if(S[i+5-k][j+k]=='#') ++count;
            }
            if(count>=4){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
}
