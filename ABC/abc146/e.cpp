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
    ll n, k;
    cin >> n >> k;
    vll a(n);
    rep(i, n) cin >> a[i];

    vll s(n+1, 0);
    ll t = 0;
    s[0] = 0;
    rep(i, n){
        s[i+1] = a[i] + t;
        t = s[i+1];
    }
    rep(i, n+1){
        s[i] -= i;
        s[i] %= k;
        s[i] = (s[i]+k) % k;
    }
    map<ll, ll> m;
    ll count = 0;
    deque<ll> q;
    rep(i, n+1){
        if(m.find(s[i]%k)!=m.end()){
            count += m[s[i]%k];
        }
        if(m.find(s[i]%k)!=m.end()) ++m[s[i]%k];
        else m.insert({s[i]%k, 1});
        q.push_back(s[i]%k);
        if(q.size()>=k){
            ll e = q.front();
            q.pop_front();
            --m[e];
        }
    }
    cout << count << endl;
}
