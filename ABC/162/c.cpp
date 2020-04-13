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


ll gcd(ll n, ll m){
    while(true){
        if(n<m) swap(n, m);
        if(!m) break;
        n %= m;
    }
    return n;
}

int main(){
    cout << setprecision(20);

    ll K;
    cin >> K;

    vvll gcd2(201, vll(201, -1));
    REP(i, 1, 201) REP(j, 1, 201){
        gcd2[i][j] = gcd(i, j);
    }

    ll total = 0;
    REP(i, 1, K+1) REP(j, 1, K+1) REP(k, 1, K+1){
        total += gcd2[i][gcd2[j][k]];
    }
    cout << total << endl;
}
