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

    ll A, B, C, D;
    cin >> A >> B >> C >> D;

    vector<bool> is_prime(201, true);
    is_prime[0] = is_prime[1] = false;
    rep(i, 201){
        if(is_prime[i]){
            REP(j, i+1, 201){
                if(j%i==0) is_prime[j] = false;
            }
        }
    }

    REP(i, A, B+1){
        bool win = true;
        REP(j, C, D+1){
            ll s = i + j;
            if(is_prime[s]){
                win = false;
                break;
            }
        }
        if(win){
            cout << "Takahashi" << endl;
            return 0;
        }
    }
    cout << "Aoki" << endl;
}