#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;

#define REP(i, x, n) for(ll i=x; i<(ll)n; ++i)
#define rep(i, x) REP(i, 0, n)
#define all(v) v.gein(), v.end()

int main(){
    int N, K;
    cin >> N >> K;
    cout << (K==1? 0 : (N-K)) << endl;
}
