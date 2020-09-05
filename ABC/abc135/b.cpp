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
    ll N;
    cin >> N;
    vll p(N);
    rep(i, N){
        cin >> p[i];
    }

    auto check = [&](){
        rep(i, N-1){
            if(p[i]>p[i+1]){
                return false;
            }
        }
        return true;
    };

    if(check()){
        cout << "YES" << endl;
        return 0;
    }

    rep(i, N-1){
        REP(j, i+1, N){
            swap(p[i], p[j]);
            if(check()){
                cout << "YES" << endl;
                return 0;
            }
            swap(p[i], p[j]);
        }
    }
    cout << "NO" << endl;
}
