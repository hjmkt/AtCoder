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

    ll N;
    cin >> N;
    vector<string> S(N);
    rep(i, N) cin >> S[i];
    vector<pair<ll, ll>> lr1, lr2;

    rep(i, N){
        stack<char> s;
        for(char c : S[i]){
            if(s.empty()) s.push(c);
            else if(c==')' && s.top()=='(') s.pop();
            else s.push(c);
        }
        ll l = 0, r = 0;
        while(!s.empty()){
            char c = s.top();
            s.pop();
            if(c=='(') ++l;
            else ++r;
        }
        if(l>=r) lr1.push_back({l, r});
        else if(l<r) lr2.push_back({l, r});
    }
    sort(all(lr1), [](auto lhs, auto rhs){ return lhs.second<rhs.second; });
    sort(all(lr2), [](auto lhs, auto rhs){ return lhs.first<rhs.first; });

    ll sl = 0, sr = 0;
    for(auto p : lr1){
        if(sl<p.second){
            cout << "No" << endl;
            return 0;
        }
        sl += p.first - p.second;
    }
    for(auto p : lr2){
        if(sr<p.first){
            cout << "No" << endl;
            return 0;
        }
        sr += p.second - p.first;
    }
    if(sl==sr) cout << "Yes" << endl;
    else cout << "No" << endl;
}
