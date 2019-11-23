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
    string s;
    cin >> s;
    ll k;
    cin >> k;
    
    auto count = [](string s){
        ll c = 0;
        rep(i, (ll)s.size()-1){
            if(s[i]==s[i+1]){
                if(i+2<s.size()){
                    if(s[i+1]==s[i+2]) ++i; 
                }
                ++c;
            }
        }
        return c;
    };

    string s0 = s, s1 = s+s, s2 = s+s+s, s3 = s+s+s+s;
    ll c0 = count(s0);
    ll c1 = count(s1);
    ll c2 = count(s2);
    ll c3 = count(s3);

    if(k==1) cout << c0 << endl;
    else if(k==2) cout << c1 << endl;
    else if(k%2==0) cout << (c1 + (c3-c1)*(k/2-1)) << endl;
    else cout << (c0 + (c2-c0)*(k/2)) << endl;
}
