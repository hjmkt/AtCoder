#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;

#define REP(i, x, n) for(ll i=x; i<(ll)n; ++i)
#define rep(i, n) REP(i, 0, n)
#define all(v) v.begin(), v.end()

int main(){
    ll N;
    cin >> N;
    vll d(N);
    rep(i, N){
        cin >> d[i];
    }
    sort(d.begin(), d.end());
    if(d[N/2-1]!=d[N/2]){
        cout << abs(d[N/2]-d[N/2-1]) << endl;
    }
    else{
        cout << 0 << endl;
    }
}
