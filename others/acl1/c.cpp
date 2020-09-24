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
    vector<T> prev(e.size(), -1);
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


vector<unordered_map<ll, ll>> min_cost_flow(vector<unordered_map<ll, array<ll, 2>>> e, ll src, ll dst, ll flow){
    vector<unordered_map<ll, ll>> f(e.size()), t(e.size());
    rep(i, e.size()){
        for(auto p : e[i]){
            f[i][p.first] = 0;
            t[i][p.first] = p.second[1];
        }
    }
    while(flow>0){
        auto [s, prev] = djkstra(t, src);
        if(s[dst]==LLONG_MAX) return f;
        vll path;
        ll last = dst;
        while(last>=0){
            path.push_back(last);
            last = prev[last];
        }
        reverse(all(path));
        assert(path[0]==src);
        assert(path[path.size()-1]==dst);
        rep(i, t.size()) for(auto p : t[i]){
            t[i][p.first] += s[i] - s[p.first];
        }
        ll m = flow;
        rep(i, path.size()-1) m = min(m, e[path[i]][path[i+1]][0]);
        rep(i, path.size()-1){
            f[path[i]][path[i+1]] += m;
            f[path[i+1]][path[i]] -= m;
            e[path[i]][path[i+1]][0] -= m;
            e[path[i+1]][path[i]][0] += m;
            if(t[path[i+1]].find(path[i])==t[path[i+1]].end()) t[path[i+1]][path[i]] = -t[path[i]][path[i+1]];
            if(e[path[i]][path[i+1]][0]<=0) t[path[i]].erase(path[i+1]);
        }
        flow -= m;
    }
    return f;
}



int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);

    ll N, M;
    cin >> N >> M;
    vector<string> S(N);
    rep(i, N) cin >> S[i];

    vll srcs;
    rep(i, N) rep(j, M){
        if(S[i][j]=='o'){
            srcs.push_back(i*M+j);
        }
    }
    ll flow = srcs.size();

    vector<unordered_map<ll, ll>> t(N*M);
    rep(i, N) rep(j, M){
        if(i<N-1 && S[i+1][j]!='#') t[i*M+j][(i+1)*M+j] = 1;
        if(j<M-1 && S[i][j+1]!='#') t[i*M+j][i*M+j+1] = 1;
        t[i*M+j][i*M+j] = 1;
    }
    vector<unordered_map<ll, array<ll, 2>>> e(flow+N*M+2);
    rep(i, flow){
        auto [s, _] = djkstra(t, srcs[i]);
        rep(j, N*M){
            if(s[j]<N+M && s[j]>=0){
                e[i+1][flow+j+1] = {1, N+M-abs(srcs[i]/M-j/M)-abs(srcs[i]%M-j%M)};
            }
        }
        e[0][i+1] = {1, 0};
    }
    rep(i, N*M) e[flow+i+1][flow+N*M+1] = {1, 0};
    auto f = min_cost_flow(e, 0, flow+N*M+1, flow);
    ll ans = 0;
    rep(i, flow) rep(j, N*M){
        if(f[i+1][flow+j+1]>0){
            ans += abs(srcs[i]/M-j/M) + abs(srcs[i]%M-j%M);
        }
    }
    cout << ans << endl;
}
