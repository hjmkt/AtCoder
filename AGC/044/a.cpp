#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
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

    ull T;
    cin >> T;
    rep(t, T){
        ull N, A, B, C, D;
        cin >> N >> A >> B >> C >> D;

        ull total = 0;
        unordered_map<ull, ull> m;
        queue<pair<ull, ull>> q;
        q.push({N, 0});
        auto uq = [&](pair<ull, ull> np){
            auto it = m.find(np.first);
            if(it!=m.end()){
                if(np.second<it->second){
                    m[np.first] = np.second;
                    q.push(np);
                }
            }
            else{
                m[np.first] = np.second;
                q.push(np);
            }
        };
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            if(p.first==0) continue;
            if(p.first%2==0){
                pair<ull, ull> np = {p.first/2, p.second+A};
                uq(np);
            }
            else{
                pair<ull, ull> np1 = {(p.first+1)/2, p.second+A+D};
                pair<ull, ull> np2 = {(p.first-1)/2, p.second+A+D};
                uq(np1);
                uq(np2);
            }
            if(p.first%3==0){
                pair<ull, ull> np = {p.first/3, p.second+B};
                uq(np);
            }
            else{
                pair<ull, ull> np1 = {(p.first+(3-p.first%3))/3, p.second+B+D*(3-p.first%3)};
                pair<ull, ull> np2 = {(p.first-p.first%3)/3, p.second+B+D*(p.first%3)};
                uq(np1);
                uq(np2);
            }
            if(p.first%5==0){
                pair<ull, ull> np = {p.first/5, p.second+C};
                uq(np);
            }
            else{
                pair<ull, ull> np1 = {(p.first+(5-p.first%5))/5, p.second+C+D*(5-p.first%5)};
                pair<ull, ull> np2 = {(p.first-p.first%5)/5, p.second+C+D*(p.first%5)};
                uq(np1);
                uq(np2);
            }
            uq({0, p.second+p.first*D});
        }
        cout << m[0] << endl;
    }
}
