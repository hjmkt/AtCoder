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
    vll S(N);
    rep(i, N) cin >> S[i];

    if(N==1){
        cout << "Yes" << endl;
        cout << S[0] << " 0 0" << endl;
        return 0;
    }
    if(N==2){
        cout << "Yes" << endl;
        cout << S[0] << " 0 0 " << S[1] << endl;
        return 0;
    }

    vll d(3, 0), l(3, 0);
    rep(i, N-1){
        ll m = i % 3;
        ll diff = S[i+1] - S[i];
        l[m] += diff;
        d[m] = max(d[m], -l[m]);
    }
    if(d[0]+d[1]+d[2]<=S[0]){
        cout << "Yes" << endl;
        vll t = {d[0], d[1], S[0] - d[0] - d[1]};
        vll ans;
        rep(i, 3){
            ans.push_back(t[i]);
        }
        REP(i, 3, N+2){
            ll m = i%3;
            t[m] += S[i-2] - S[i-3];
            ans.push_back(t[m]);
        }
        rep(i, ans.size()-1) cout << ans[i] << " ";
        cout << ans[ans.size()-1] << endl;
    }
    else{
        cout << "No" << endl;
    }
}
