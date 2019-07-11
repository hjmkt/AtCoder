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
    ll y, m, d;
    cin >> y >> m >> d;

    auto ymd_to_days = [](ll y, ll m, ll d){
        if(m==1||m==2){
            y -= 1;
            m += 12;
        }
        ll days = 365*y + y/4 - y/100 + y/400 + 306*(m+1)/10 + d - 429;
        return days;
    };
    cout << (ymd_to_days(2014, 5, 17)-ymd_to_days(y, m, d)) << endl;
}
