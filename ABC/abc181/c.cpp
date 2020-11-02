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
    vll x(N), y(N);
    rep(i, N) cin >> x[i] >> y[i];

    set<pair<double, double>> s;
    bool found = false;
    rep(i, N) REP(j, i+1, N){
        ll x1 = x[i], y1 = y[i];
        ll x2 = x[j], y2 = y[j];
        if(x1>x2){
            swap(x1, x2);
            swap(y1, y2);
        }
        else if(x1==x2){
            double a = DBL_MAX;
            double b = x1;
            if(s.count({a, b})>0){
                found = true;
                break;
            }
            s.insert({a, b});
            continue;
        }
        double a = (double)(y2-y1) / (double)(x2-x1);
        double b = (double)y1 - a*(double)x1;
        if(s.count({a, b})>0){
            found = true;
            break;
        }
        s.insert({a, b});
    }
    if(found) cout << "Yes" << endl;
    else cout << "No" << endl;
}
