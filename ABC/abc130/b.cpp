#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;

#define REP(i, x, n) for(ll i=x; i<(ll)n; ++i)
#define rep(i, n) REP(i, 0, n)
#define all(v) v.begin(), v.end()

int main(){
    int N, X;
    cin >> N >> X;
    vll l(N);
    rep(i, N){
        cin >> l[i];
    }
    ll count = 1;
    ll current = 0;
    rep(i, N){
        current += l[i];
        if(current>X) break;
        ++count;
    }
    cout << count << endl;
}
