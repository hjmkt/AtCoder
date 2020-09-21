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

pair<ll, ll> exgcd(ll a, ll b){
    if(b==0) return {1, 0};
    auto p = exgcd(b, a%b);
    return {p.second, p.first-a/b*p.second};
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);

    ll N;
    cin >> N;

    vll ds;
    REP(i, 1, (ll)sqrt(2*N+1)+1){
        if(2*N%i==0){
            ds.push_back(i);
            ds.push_back(2*N/i);
        }
    }

    ll m = LLONG_MAX;
    for(ll a : ds){
        ll b = 2*N / a;
        auto p = exgcd(a, b);
        ll k = (a*p.first*-1 % (a*b) + a*b) % (a*b);
        if(k>0 && k*(k+1)/2%N==0) m = min(m, k);
    }
    cout << m << endl;
}
