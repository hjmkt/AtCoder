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
    ll n;
    string s;
    cin >> n;
    cin >> s;

    unordered_set<string> d1;
    unordered_set<string> d2;
    unordered_set<string> d3;
    rep(i, s.length()){
        for(auto c : d2){
            d3.insert(c+s[i]);
        }
        for(auto c : d1){
            d2.insert(c+s[i]);
        }
        d1.insert(string{s[i]});
    }
    cout << d3.size() << endl;
}
