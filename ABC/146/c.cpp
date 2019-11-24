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

int main(){
    cout << setprecision(20);
    ll a, b, x;
    cin >> a >> b >> x;

    ll left = 0, right = 1000000000;
    while(left<right){
        ll mid = (left+right+1)/2;
        ll d = 0;
        ll t = mid;
        while(t>0){
            ++d;
            t /= 10;
        }
        ll c = a*mid + b*d;
        if(c<=x){
            left = mid;
        }
        else{
            right = mid-1;
        }
    }
    cout << left << endl;
}
