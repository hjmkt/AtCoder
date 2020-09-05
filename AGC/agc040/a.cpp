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
    string s;
    cin >> s;

    vll lbs(s.length()+1, 0);
    ll idx = 0;
    ll ndec = 0;
    ll c = 0;
    while(idx<s.length()){
        if(s[idx]=='>') ++ndec;
        else{
            while(ndec>0){
                lbs[c] = ndec;
                --ndec;
                ++c;
            }
            c = idx+1;
        }
        ++idx;
    }
    if(ndec>0){
        while(ndec>0){
            lbs[c] = ndec;
            --ndec;
            ++c;
        }
    }
    ll lb = 0;
    ll sum = 0;
    rep(i, lbs.size()){
        lb = max(lb, lbs[i]);
        sum += lb;
        if(i<s.length()){
            if(s[i]=='<') ++lb;
            else lb = 0;
        }
    }
    cout << sum << endl;
}
