#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;

#define REP(i, n, m) for(ll i=n; i<(ll)m; ++i)
#define IREP(i, n, m) for(ll i=n-1; i>=m; --i)
#define rep(i, n) REP(i, 0, n)
#define irep(i, n) IREP(i, n, 0)
#define all(v) v.begin(), v.end()

int main(){
    ll N;
    cin >> N;
    auto f = [](ll n){
        ll count = 1;
        while(n>=10){
            ++count;
            n /= 10;
        }
        return count;
    };
    ll total = 0;
    REP(i, 1, N+1){
        if(f(i)%2==1){
            ++total;
        }
    }
    cout << total << endl;
}
