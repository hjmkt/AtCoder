#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;
using vull = vector<ull>;

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

    ll N;
    cin >> N;

    vull S(N), T(N), U(N), V(N);
    rep(i, N) cin >> S[i];
    rep(i, N) cin >> T[i];
    rep(i, N) cin >> U[i];
    rep(i, N) cin >> V[i];

    vvvll t(64, vvll(N, vll(N, -1)));
    bool possible = true;
    rep(i, 64){
        rep(j, N) rep(k, N) if(((U[j]>>i)&1)==((V[k]>>i)&1)) t[i][j][k] = (U[j]>>i) & 1;
        rep(j, N){
            if(S[j]==0){
                rep(k, N) if(((U[j]>>i)&1)==1){
                    possible &= t[i][j][k]!=0;
                    t[i][j][k] = 1;
                }
            }
            else rep(k, N) if(((U[j]>>i)&1)==0){
                possible &= t[i][j][k]!=1;
                t[i][j][k] = 0;
            }
            if(T[j]==0){
                rep(k, N) if(((V[j]>>i)&1)==1){
                    possible &= t[i][k][j]!=0;
                    t[i][k][j] = 1;
                }
            }
            else rep(k, N) if(((V[j]>>i)&1)==0){
                possible &= t[i][k][j]!=1;
                t[i][k][j] = 0;
            }
        }
    }
    if(possible){
        rep(i, 64) rep(j, N) rep(k, N) if(t[i][j][k]<0) t[i][j][k] = 0;
        rep(i, 64){
            vll r(N, -1), c(N, -1);
            rep(j, N){
                if(S[j]==1 && ((U[j]>>i)&1)==1){
                    bool found = false;
                    rep(k, N) found |= t[i][j][k]==1;
                    if(!found) r[j] = 1;
                }
                if(T[j]==1 && ((V[j]>>i)&1)==1){
                    bool found = false;
                    rep(k, N) found |= t[i][k][j]==1;
                    if(!found) c[j] = 1;
                }
            }
            vll rcnt(N, 0), ccnt(N, 0);
            rep(j, N) rep(k, N){
                if(t[i][j][k]==0) ++rcnt[j];
                if(t[i][k][j]==0) ++ccnt[j];
            }
            rep(j, N) if(r[j]==1) rep(k, N){
                if(t[i][j][k]==0 && T[k]==0 && ((V[k]>>i)&1)==0 && ccnt[k]>=2){
                    t[i][j][k] = 1;
                    ++rcnt[j];
                    --ccnt[k];
                    break;
                }
            }
            rep(j, N) if(c[j]==1) rep(k, N){
                if(t[i][k][j]==0 && S[k]==0 && ((U[k]>>i)&1)==0 && rcnt[k]>=2){
                    t[i][k][j] = 1;
                    --rcnt[k];
                    ++ccnt[j];
                    break;
                }
            }
            rep(j, N){
                ull r = 1-S[j], c = 1-T[j];
                rep(k, N){
                    r = S[j]==0? (r&t[i][j][k]) : (r|t[i][j][k]);
                    c = T[j]==0? (c&t[i][k][j]) : (c|t[i][k][j]);
                }
                possible &= r==((U[j]>>i)&1) && c==((V[j]>>i)&1);
            }
        }
        if(possible) rep(i, N){
            rep(j, N){
                ull n = 0;
                irep(k, 64) n = (n<<1) + t[k][i][j];
                cout << n << " ";
            }
            cout << endl;
        }
        else cout << -1 << endl;
    }
    else cout << -1 << endl;
}
