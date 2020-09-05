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

    ll len = s.length();
    ll dp[len][13] = {};
    ll mt[len][10] = {};

    rep(i, len){
        if(i==0){
            rep(j, 10){
                mt[i][j] = j;
            }
        }
        else if(i==1){
            rep(j, 10){
                mt[i][j] = (j*10)%13;
            }
        }
        else{
            rep(j, 10){
                ll t = j*100 % 13;
                mt[i][j] = (mt[i-2][1]*t) % 13;
            }
        }
    }

    rep(i, len){
        if(i==0){
            if(s[len-1]=='?'){
                rep(j, 13){
                    dp[0][j] = (j<=5||j>=9)? 1 : 0;
                }
            }
            else{
                rep(j, 13){
                    dp[0][j] = ((ll)(s[len-1]-'0')+j)%13==5? 1 : 0;
                }
            }
        }
        else{
            if(s[len-1-i]=='?'){
                rep(j, 13){
                    ll count = 0;
                    rep(k, 10){
                        ll r = (mt[i][k]+j) % 13;
                        count += dp[i-1][r];
                    }
                    dp[i][j] = count % 1000000007;
                }
            }
            else{
                rep(j, 13){
                    ll r = (mt[i][s[len-1-i]-'0']+j) % 13;
                    dp[i][j] = dp[i-1][r] % 1000000007;
                }
            }
        }
    }
    cout << dp[len-1][0] << endl;
}
