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
    ll m;
    cin >> m;

    vll d(m), c(m);
    rep(i, m) cin >> d[i] >> c[i];

    vector<pair<ll, ll>> t = {{0, 0}, {10, 10}, {10, 11}, {4, 4}, {10, 13}, {10, 14}, {4, 5}, {10, 16}, {10, 17}, {2, 2}};
    ll count = 0;
    rep(i, m){
        if(d[i]==0){
            count += c[i];
            c[i] = 0;
        }
        else{
            while(c[i]>=t[d[i]].first){
                count += c[i]/t[d[i]].first*t[d[i]].second;
                c[i] = c[i]/t[d[i]].first + c[i]%t[d[i]].first;
            }
        }
    }
    vll s;
    rep(i, m){
        rep(j, c[i]) s.push_back(d[i]);
    }
    ll r = s[0];
    REP(i, 1, s.size()){
        r += s[i];
        ++count;
        if(r>=10){
            ++count;
            r = r/10 + r%10;
        }
    }
    cout << count << endl;
}
