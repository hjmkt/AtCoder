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
    ll M;
    cin >> M;
    vvll op(M, vll(2, 0));
    rep(i, M){
        cin >> op[i][0];
        if(op[i][0]>=3) cin >> op[i][1];
    }
    ll Q;
    cin >> Q;
    vll A(Q), B(Q);
    rep(i, Q) cin >> A[i] >> B[i];

    ll a = 1, b = 0, c = 0;
    ll d = 0, e = 1, f = 0;

    vll as = {a}, bs = {b}, cs = {c}, ds = {d}, es = {e}, fs = {f};

    rep(m, M){
        switch(op[m][0]){
            case 1:{
                ll u = a, v = b, w = c;
                a = d;
                b = e;
                c = f;
                d = -u;
                e = -v;
                f = -w;
                break;
            }
            case 2:{
                ll u = a, v = b, w = c;
                a = -d;
                b = -e;
                c = -f;
                d = u;
                e = v;
                f = w;
                break;
            }
            case 3:{
                a = -a;
                b = -b;
                c = -c + 2*op[m][1];
                break;
            }
            case 4:{
                d = -d;
                e = -e;
                f = -f + 2*op[m][1];
                break;
            }
        }
        as.push_back(a);
        bs.push_back(b);
        cs.push_back(c);
        ds.push_back(d);
        es.push_back(e);
        fs.push_back(f);
    }

    rep(q, Q){
        ll x = as[A[q]]*X[B[q]-1] + bs[A[q]]*Y[B[q]-1] + cs[A[q]];
        ll y = ds[A[q]]*X[B[q]-1] + es[A[q]]*Y[B[q]-1] + fs[A[q]];
        cout << x << " " << y << endl;
    }
}
