#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;

#define REP(i, x, n) for(ll i=x; i<(ll)n; ++i)
#define rep(i, n) REP(i, 0, n)
#define all(v) v.begin(), v.end()

int main(){
    vvll a(4, vll(4, 0));
    rep(i, 4){
        rep(j, 4){
            cin >> a[i][j];
        }
    }
    rep(i, 4){
        rep(j, 3){
            if(a[i][j]==a[i][j+1] || a[j][i]==a[j+1][i]){
                cout << "CONTINUE" << endl;
                return 0;
            }
        }
    }
    cout << "GAMEOVER" << endl;
}
