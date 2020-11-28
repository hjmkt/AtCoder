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
#define vprint(v) for(auto e:v){cout<<e<<" ";};cout<<endl;
#define vvprint(vv) for(auto v:vv){vprint(v)};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);

    ll n;
    cin >> n;

    ll total = 0;
    ll left = 1;
    ll right = n;
    ll skip = 101;
    while(n>1){
        ++total;
        skip = right;
        ++left;
        --right;
        ll next = skip-left;
        if(next<right && next>left){
            total += right - next;
            right = next;
        }
        else break;
    }
    total += right - left + 1;
    cout << total << endl;
}
