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

    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    while(k>=1){
        string t = s;
        int idx = 0;
        for(int i=0; i<s.length()*2; i+=2){
            int j = i%s.length();
            int k = (i+1)%s.length();
            if(s[j]=='R'){
                if(s[k]=='S' || s[k]=='R') t[idx] = 'R';
                else t[idx] = 'P';
            }
            else if(s[j]=='P'){
                if(s[k]=='R' || s[k]=='P') t[idx] = 'P';
                else t[idx] = 'S';
            }
            else{
                if(s[k]=='P' || s[k]=='S') t[idx] = 'S';
                else t[idx] = 'R';
            }
            ++idx;
        }
        --k;
        s = t;
    }
    cout << s[0] << endl;
}
