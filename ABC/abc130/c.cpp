#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;

#define REP(i, x, n) for(ll i=x; i<(ll)n; ++i)
#define rep(i, n) REP(i, 0, n)
#define all(v) v.begin(), v.end()

int main(){
    ll W, H, x, y;
    cin >> W >> H >> x >> y;
    cout << ((double)W * (double)H / 2) << " ";
    if(2*x==W && 2*y==H){
        cout << 1 << endl;
    }
    else cout << 0 << endl;
}
