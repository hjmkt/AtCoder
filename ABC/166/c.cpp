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

    ll N, M;
    cin >> N >> M;
    vll H(N), A(M), B(M);
    rep(i, N) cin >> H[i];
    rep(i, M) cin >> A[i] >> B[i];

    vll checked(N, 0);
    vector<unordered_set<ll>> e(N);
    rep(i, M){
        e[A[i]-1].insert(B[i]-1);
        e[B[i]-1].insert(A[i]-1);
    }
    vector<pair<ll, ll>> t(N);
    rep(i, N){
        t[i].first = i;
        t[i].second = H[i];
    }
    sort(all(t), [](auto l, auto r){ return l.second>r.second; });
    ll count = 0;
    rep(i, N){
        ll n = t[i].first;
        bool ok = true;
        for(ll s : e[n]){
            checked[s] = 1;
            e[s].erase(n);
            ok &= H[n]>H[s];
        }
        if(ok && !checked[n]) ++count;
        checked[n] = 1;
    }
    cout << count << endl;
}
