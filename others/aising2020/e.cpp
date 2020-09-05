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
#define vvprint(vv) for(auto v:vv)vprint(v);

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);

    ll T;
    cin >> T;
    REP(t, 1, T+1){
        ll N;
        cin >> N;
        vvll KLR(N, vll(3, 0));
        rep(i, N){
            cin >> K[i][0] >> K[i][1] >> K[i][2];
        }
        sort(all(KLR), [](auto l, auto r){
            if(l[0]<r[0]) return true;
            else if(l[0]==r[0]) return (l[1]-l[2])<(r[1]-r[2]);
            else return false;
        });
        vll l_total(N, KLR[0][1]);
        vll r_total(N, KLR[0][2]);
        REP(i, 1, N){
            l_total[i] = l_total[i-1] + KLR[i][1];
            r_total[i] = r_total[i-1] + KLR[i][2];
        }
        ll best = 0;
    }
}
