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

    string last = "";
    string slast = "";
    ll count = 0;
    ll idx = 0;
    while(idx<s.size()){
        if(s.substr(idx, 1)!=last){
            if(idx+2==s.size() && s[idx]==s[idx+1]){
                if(slast!=last+s.substr(idx, 1)){
                    ++count;
                }
                break;
            }
            else{
                slast = last;
                last = s.substr(idx, 1);
                ++count;
                ++idx;
            }
        }
        else{
            slast = last;
            last = s.substr(idx, 2);
            ++count;
            idx += 2;
        }
    }
    cout << count << endl;
}
