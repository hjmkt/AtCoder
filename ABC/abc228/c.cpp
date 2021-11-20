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

    ll N, K;
    cin >> N >> K;
    vvll P(N, vll(3));
    rep(i, N) cin >> P[i][0] >> P[i][1] >> P[i][2];

    vll indices(N);
    rep(i, N) indices[i] = i;
    vll scores(N);
    rep(i, N){
        scores[i] = P[i][0] + P[i][1] + P[i][2];
    }
    sort(all(indices), [&](ll l, ll r){ return scores[l]>scores[r]; });
    ll t = scores[indices[K-1]];

    rep(i, N){
        if(scores[i]+300>=t) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}
