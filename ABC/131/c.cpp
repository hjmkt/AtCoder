#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;

#define REP(i, x, n) for(ll i=x; i<(ll)n; ++i)
#define rep(i, n) REP(i, 0, n)
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
    ll A, B, C, D;
    cin >> A >> B >> C >> D;

    ll b = abs(B) - abs(B)/C - abs(B)/D + abs(B)/C*gcd(C, D)/D;
    ll a = abs(A-1) - abs(A-1)/C - abs(A-1)/D + abs(A-1)/C*gcd(C, D)/D;
    cout << (b-a) << endl;
}
