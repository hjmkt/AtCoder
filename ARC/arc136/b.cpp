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
    vll A(N), B(N);
    rep(i, N) cin >> A[i];
    rep(i, N) cin >> B[i];

    unordered_map<ll, ll> ma, mb;
    rep(i, N) ++ma[A[i]];
    rep(i, N) ++mb[B[i]];
    for(auto p: ma){
        if(mb[p.first]!=p.second){
            cout << "No" << endl;
            return 0;
        }
    }
    for(auto p: mb){
        if(ma[p.first]!=p.second){
            cout << "No" << endl;
            return 0;
        }
    }

    for(auto p: ma){
        if(p.second>=2){
            cout << "Yes" << endl;
            return 0;
        }
    }

    ll sa = 0, sb = 0;
    rep(i, N-1){
        REP(j, i+1, N){
            if(A[i]>A[j]) ++sa;
            if(B[i]>B[j]) ++sb;
        }
    }
    if(sa%2==sb%2){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}
