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

class STree{
public:
    vector<STree*> nexts = vector<STree*>(26, nullptr);
    bool end = false;

    void append(string &s, ll idx){
        if(idx<0) this->end = true;
        else{
            if(this->nexts[s[idx]-'a']){
                this->nexts[s[idx]-'a']->append(s, idx-1);
            }
            else{
                this->nexts[s[idx]-'a'] = new STree();
                this->nexts[s[idx]-'a']->append(s, idx-1);
            }
        }
    }

    ll solve_sub(string &s, vector<vector<bool>> &t, ll idx){
        if(idx<0) return 0;
        else{
            ll count = 0;
            rep(i, 26){
                if(this->nexts[i] && this->nexts[i]->end && t[idx][i]){
                    ++count;
                }
            }
            if(this->nexts[s[idx]-'a']) return count + this->nexts[s[idx]-'a']->solve_sub(s, t, idx-1);
            else return count;
        }
    }

    ll solve(string &s){
        vector<vector<bool>> t(s.length(), vector<bool>(26, false));
        rep(i, s.length()){
            if(i==0){
                t[i][s[i]-'a'] = true;
            }
            else{
                rep(j, 26) t[i][j] = t[i-1][j];
                t[i][s[i]-'a'] = true;
            }
        }
        return solve_sub(s, t, s.length()-1);
    }
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);

    ll N;
    cin >> N;
    vector<string> S(N);
    rep(i, N) cin >> S[i];

    STree st;
    rep(i, N){
        st.append(S[i], S[i].length()-1);
    }
    ll total = 0;
    rep(i, N){
        total += st.solve(S[i]);
    }
    total -= N;
    cout << total << endl;
}
