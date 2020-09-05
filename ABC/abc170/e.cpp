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

    ll N, Q;
    cin >> N >> Q;
    vll A(N), B(N);
    vll C(Q), D(Q);
    rep(i, N){
        cin >> A[i] >> B[i];
        --B[i];
    }
    rep(i, Q){
        cin >> C[i] >> D[i];
        --C[i];
        --D[i];
    }

    map<ll, unordered_set<ll>> r2s;
    vector<map<ll, ll>> r2c(2*100000);
    rep(i, N){
        if(r2c[B[i]].find(A[i])==r2c[B[i]].end()) r2c[B[i]][A[i]] = 1;
        else ++r2c[B[i]][A[i]];
    }
    rep(i, 2*100000){
        ll mr = r2c[i].size()>0? r2c[i].rbegin()->first : -1;
        if(mr>=0) r2s[mr].insert(i);
    }
    rep(i, Q){
        ll c = C[i];
        if(A[c]==r2c[B[c]].rbegin()->first && r2c[B[c]].rbegin()->second==1){
            r2c[B[c]].erase(A[c]);
            r2s[A[c]].erase(B[c]);
            if(r2s[A[c]].size()==0){
                r2s.erase(A[c]);
                ll nr = r2c[B[c]].size()>0? r2c[B[c]].rbegin()->first : -1;
                if(nr>=0) r2s[nr].insert(B[c]);
            }
        }
        else{
            if(r2c[B[c]][A[c]]>1) --r2c[B[c]][A[c]];
            else r2c[B[c]].erase(A[c]);
        }
        if(r2c[D[i]].find(A[c])==r2c[D[i]].end()){
            ll pr = r2c[D[i]].size()>0? r2c[D[i]].rbegin()->first : -1;
            r2c[D[i]][A[c]] = 1;
            if(r2c[D[i]].rbegin()->first==A[c]){
                if(pr>=0){
                    r2s[pr].erase(D[i]);
                    if(r2s[pr].size()==0) r2s.erase(pr);
                }
                r2s[A[c]].insert(D[i]);
            }
        }
        else ++r2c[D[i]][A[c]];
        B[c] = D[i];
        cout << r2s.begin()->first << endl;
    }
}
