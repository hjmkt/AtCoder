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

template<typename T=ll>
pair<vector<ll>, vector<ll>> djkstra(vector<unordered_map<ll, T>> &e, ll src, function<bool(const T&, const T&)> comp=greater<T>()){
    auto c = [&comp](tuple<T, ll, ll> l, tuple<T, ll, ll> r){ return comp(get<0>(l), get<0>(r)); };
    priority_queue<tuple<T, ll, ll>, vector<tuple<T, ll, ll>>, decltype(c)> q(c);
    vector<T> s(e.size(), LLONG_MAX);
    vector<ll> prev(e.size(), -1);
    q.push({0, src, -1});
    while(!q.empty()){
        auto [d, n, p] = q.top();
        q.pop();
        if(s[n]<LLONG_MAX) continue;
        s[n] = d;
        prev[n] = p;
        for(auto t : e[n]){
            if(s[t.first]<LLONG_MAX) continue;
            q.push({d+t.second, t.first, n});
        }
    }
    return {s, prev};
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);

    ll H, W, N;
    cin >> H >> W >> N;
    ll sx, sy, gx, gy;
    cin >> sx >> sy >> gx >> gy;
    vll X(N), Y(N);
    rep(i, N) cin >> X[i] >> Y[i];

    map<ll, set<ll>> xs_in_row, ys_in_col;
    rep(i, N){
        xs_in_row[Y[i]-1].insert(X[i]-1);
        xs_in_row[Y[i]-1].insert(LLONG_MAX);
    }
    rep(i, N){
        ys_in_col[X[i]-1].insert(Y[i]-1);
        ys_in_col[X[i]-1].insert(LLONG_MAX);
    }

    queue<tuple<ll, ll, ll>> q;
    q.push({0, sx-1, sy-1});

    set<pair<ll, ll>> visited;

    while(!q.empty()){
        auto [d, x, y] = q.front();
        q.pop();
        if(x==gx-1 && y==gy-1){
            cout << d << endl;
            return 0;
        }
        if(visited.find({x, y})!=visited.end()) continue;
        visited.insert({x, y});
        if(x>0){
            if(xs_in_row[y].size()>0){
                auto it = xs_in_row[y].lower_bound(x);
                if(it!=xs_in_row[y].begin()){
                    it = prev(it);
                }
                if(*it<x){
                    if(visited.find({*it+1, y})==visited.end()){
                        q.push({d+1, *it+1, y});
                    }
                }
            }
        }
        if(y>0){
            if(ys_in_col[x].size()>0){
                auto it = ys_in_col[x].lower_bound(y);
                if(it!=ys_in_col[x].begin()){
                    it = prev(it);
                }
                if(*it<y){
                    if(visited.find({x, *it+1})==visited.end()){
                        q.push({d+1, x, *it+1});
                    }
                }
            }
        }
        if(x<H-1){
            if(xs_in_row[y].size()>0){
                auto it = xs_in_row[y].lower_bound(x+1);
                if(*it>x && *it<LLONG_MAX){
                    if(visited.find({*it-1, y})==visited.end()){
                        q.push({d+1, *it-1, y});
                    }
                }
            }
        }
        if(y<W-1){
            if(ys_in_col[x].size()>0){
                auto it = ys_in_col[x].lower_bound(y+1);
                if(*it>y && *it<LLONG_MAX){
                    if(visited.find({x, *it-1})==visited.end()){
                        q.push({d+1, x, *it-1});
                    }
                }
            }
        }
    }
    cout << -1 << endl;
}
