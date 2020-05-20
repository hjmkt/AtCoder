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

    ll N, M;
    cin >> N >> M;
    vll A(N), B(N), C(N);
    vll D(M), E(M), F(M);
    rep(i, N) cin >> A[i] >> B[i] >> C[i];
    rep(i, M) cin >> D[i] >> E[i] >> F[i];

    set<ll> xs = {0}, ys = {0};
    rep(i, N){
        xs.insert(A[i]);
        xs.insert(B[i]);
        ys.insert(C[i]);
    }
    rep(i, M){
        ys.insert(E[i]);
        ys.insert(F[i]);
        xs.insert(D[i]);
    }
    unordered_map<ll, ll> xm, ym;
    vll xv(xs.size()), yv(ys.size());
    ll idx = 0;
    for(ll x : xs){
        xm[x] = idx;
        xv[idx++] = x;
    }
    idx = 0;
    for(ll y : ys){
        ym[y] = idx;
        yv[idx++] = y;
    }

    vector<vector<bool>> m(ys.size()*2, vector<bool>(xs.size()*2, 0));
    rep(i, N) REP(j, xm[A[i]]*2, xm[B[i]]*2+1) m[ym[C[i]]*2][j] = 1;
    rep(i, M) REP(j, ym[E[i]]*2, ym[F[i]]*2+1) m[j][xm[D[i]]*2] = 1;

    ll cx = xm[0]*2, cy = ym[0]*2, a = 0;
    ll xmax = xs.size()*2 - 2, ymax = ys.size()*2 - 2;
    vvll dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    vll ws(xs.size()), hs(ys.size());
    rep(i, xs.size()-1) ws[i] = xv[i+1] - xv[i];
    rep(i, ys.size()-1) hs[i] = yv[i+1] - yv[i];
    queue<pair<ll, ll>> q;
    q.push({cx, cy});
    m[cy][cx] = 1;
    while(!q.empty()){
        auto p = q.front();
        q.pop();
        if(p.first==0 || p.first==xmax || p.second==0 || p.second==ymax){
            cout << "INF" << endl;
            return 0;
        }
        if(p.first%2==1 && p.second%2==1) a += ws[p.first/2] * hs[p.second/2];
        for(auto d : dirs){
            ll nx = p.first + d[0], ny = p.second + d[1];
            if(!m[ny][nx]) q.push({nx, ny}), m[ny][nx] = 1;
        }
    }
    cout << a << endl;
}
