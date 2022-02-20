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

    ll N;
    cin >> N;
    vll a(N);
    rep(i, N) cin >> a[i];

    ll last = -1;
    ll total = 0;

    vector<pair<ll, ll>> v;

    rep(i, N){
        ++total;
        if(v.size()>0 && v.back().first==a[i]){
            ++v.back().second;
        }
        else{
            v.push_back({a[i], 1});
        }
        if(v.size()>0 && v.back().first==v.back().second){
            total -= v.back().first;
            v.pop_back();
        }
        cout << total << endl;
    }
}
