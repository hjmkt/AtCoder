#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;
template<class T> using uset = unordered_set<T>;
template<class T, class U> using umap = unordered_map<T, U>;

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
    ll Ax, Ay, Bx, By;
    cin >> Ax >> Ay >> Bx >> By;
    vector<string> S(N);
    rep(i, N) cin >> S[i];

    auto c = [](pair<ll, ll> l, pair<ll, ll> r){ return l.first>r.first; };
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, decltype(c)> q(c);
    vll s(N*N, LLONG_MAX);
    q.push({0, (Ay-1)*N+(Ax-1)});

    while(!q.empty()){
        auto [d, n] = q.top();
        q.pop();
        s[n] = d;
        ll x = n%N, y = n/N;
        ll dir[4][2] = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
        rep(i, 4){
            REP(j, 1, N){
                ll nx = x + dir[i][0]*j;
                ll ny = y + dir[i][1]*j;
                if(nx<0 || nx>=N || ny<0 || ny>=N) break;
                if(S[nx][ny]=='#') break;
                if(s[ny*N+nx]<d+1) break;
                if(s[ny*N+nx]<LLONG_MAX) continue;
                s[ny*N+nx] = d+1;
                q.push({d+1, ny*N+nx});
            }
        }
    }

    ll n = (By-1)*N+(Bx-1);
    if(s[n]<LLONG_MAX){
        cout << s[n] << endl;
    }
    else{
        cout << -1 << endl;
    }
}

