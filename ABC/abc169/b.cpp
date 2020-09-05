#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using vll = vector<ll>;
using vull = vector<ull>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;

#define REP(i, n, m) for(ll i=n; i<(ll)m; ++i)
#define IREP(i, n, m) for(ll i=n-1; i>=m; --i)
#define rep(i, n) REP(i, 0, n)
#define irep(i, n) IREP(i, n, 0)
#define all(v) v.begin(), v.end()
#define vprint(v) for(auto e:v){cout<<e<<" ";};cout<<endl;
#define vvprint(vv) for(auto v:vv)vprint(v);

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);

    ull N;
    cin >> N;
    vull A(N);
    bool zero = false;
    rep(i, N){
        cin >> A[i];
        if(A[i]==0) zero = true;
    }

    if(zero){
        cout << 0 << endl;
        return 0;
    }

    ull ans = 1;
    rep(i, N){
        if(ans>1000000000000000000ull/A[i]){
            cout << -1 << endl;
            return 0;
        }
        ans *= A[i];
    }
    cout << ans << endl;
}
