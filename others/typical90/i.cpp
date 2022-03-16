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

    ll N;
    cin >> N;
    vll X(N), Y(N);
    rep(i, N) cin >> X[i] >> Y[i];

    vector<set<long double>> angles(N);
    rep(i, N){
        rep(j, N){
            if(i==j) continue;
            long double dx = X[i] - X[j];
            long double dy = Y[i] - Y[j];
            long double angle = atan2(dy, dx) / M_PI * 180 + 180;
            angles[i].insert(angle);
        }
    }
    long double ans = 0;
    rep(i, N){
        for(long double a0: angles[i]){
            auto it = angles[i].lower_bound(a0>=180? (a0-180) : (a0+180));
            long double a1 = it==angles[i].end()? *angles[i].rbegin() : *it;
            long double angle = max(a1, a0) - min(a1, a0);
            angle = min(angle, 360-angle);
            ans = max(ans, angle);
            if(it==angles[i].begin()) it = prev(angles[i].end());
            else it = prev(it);

            a1 = *it;
            angle = max(a1, a0) - min(a1, a0);
            angle = min(angle, 360-angle);
            ans = max(ans, angle);

            a1 = *angles[i].begin();
            angle = max(a1, a0) - min(a1, a0);
            angle = min(angle, 360-angle);
            ans = max(ans, angle);
        }
    }
    cout << ans << endl;
}
