#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;
template<class T> using uset = unordered_set<T>;
template<class T, class U> using umap = unordered_map<T, U>;

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

    ll N;
    cin >> N;

    ll ans = LLONG_MAX;
    rep(a, N+1){
        ll low = a, high = 1000001;
        while(low<high){
            ll b = (low+high) / 2;
            ll s = a*a*a + a*a*b + a*b*b + b*b*b;
            if(s>=N) high = b;
            else low = b + 1;
        }
        ll s = a*a*a + a*a*low + a*low*low + low*low*low;
        ans = min(ans, s);
        if(4*a*a*a>=N) break;
    }
    cout << ans << endl;
}
