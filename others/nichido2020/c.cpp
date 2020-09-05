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

class SSTree{
    public:
        ll size;
        vll v;
        vll lv;

        SSTree(ll n){
            this->size = n;
            ll m = 1;
            while(n>m) m *= 2;
            this->v = vll(2*m-1, 0);
            this->lv = vll(2*m-1, 0);
        }

        ll get(ll left, ll right, ll level=0, ll idx=0){
            if(left>right) return 0;
            ll step = (this->v.size()+1) >> (level+1);
            ll lb = (idx-(1<<level)+1) * step;
            ll ub = lb + step - 1;
            if(lb==left && ub==right){
                vll s;
                ll tmp = idx;
                do{ s.push_back(tmp=(tmp-1)/2); } while(tmp>0);
                for(auto it=s.rbegin(); it!=s.rend(); ++it){
                    for(int i=1; i<=2; ++i) v[*it*2+i] += lv[*it]/2;
                    for(int i=1; i<=2; ++i) lv[*it*2+i] += lv[*it]/2;
                    lv[*it] = 0;
                }
                return v[idx];
            }
            else return get(left, min((lb+ub)/2, right), level+1, idx*2+1) + get(max((lb+ub)/2+1, left), right, level+1, idx*2+2);
        }

        void update(ll left, ll right, ll e, ll level=0, ll idx=0){
            if(left>right) return;
            ll step = (this->v.size()+1) >> (level+1);
            ll lb = (idx-(1<<level)+1) * step;
            ll ub = lb + step - 1;
            if(lb==left && ub==right){
                this->v[idx] += e*step;
                this->lv[idx] += e*step;
            }
            else{
                ll mid = (lb+ub) / 2;
                update(left, min(mid, right), e, level+1, idx*2+1);
                update(max(mid+1, left), right, e, level+1, idx*2+2);
            }
        }
};


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);

    ll N, K;
    cin >> N >> K;
    vll A(N);
    rep(i, N) cin >> A[i];

    SSTree t(N+1);
    rep(i, N) t.update(max(0ll, i-A[i]), min(N-1, i+A[i]), 1);
    rep(i, N) A[i] = t.get(i, i);
    --K;

    ll sat_count = 0;
    vector<bool> sat(N, false);
    while(K>0){
        SSTree s(N+1);
        rep(i, N) s.update(max(0ll, i-A[i]), min(N-1, i+A[i]), 1);
        rep(i, N){
            if(!sat[i]){
                A[i] = s.get(i, i);
                if(A[i]==N){
                    sat[i] = true;
                    ++sat_count;
                }
            }
        }
        --K;
        if(sat_count==N) break;
    }
    vprint(A);
}
