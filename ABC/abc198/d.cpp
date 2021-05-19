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

    string S1, S2, S3;
    cin >> S1 >> S2 >> S3;

    set<char> s;
    for(char c : S1) s.insert(c);
    for(char c : S2) s.insert(c);
    for(char c : S3) s.insert(c);

    vector<char> v;
    for(char c : s) v.push_back(c);

    set<char> nz;
    nz.insert(S1[0]);
    nz.insert(S2[0]);
    nz.insert(S3[0]);

    ll n = s.size();
    if(n>10){
        cout << "UNSOLVABLE" << endl;
        return 0;
    }

    vll m(27, -1);

    function<vll(ll)> solve = [&](ll idx){
        if(idx>=n){
            ll n1 = 0, n2 = 0, n3 = 0;
            rep(i, S1.size()) n1 = n1*10 + m[S1[i]-'a'];
            rep(i, S2.size()) n2 = n2*10 + m[S2[i]-'a'];
            rep(i, S3.size()) n3 = n3*10 + m[S3[i]-'a'];
            if(n1+n2==n3){
                return vll{n1, n2, n3};
            }
            else{
                return vll{};
            }
        }
        if(m[v[idx]-'a']>=0){
            return solve(idx+1);
        }
        rep(i, 10){
            bool ok = true;
            for(auto e : m){
                if(e==i){
                    ok = false;
                    break;
                }
            }
            if(!ok) continue;
            if(i==0 && (nz.find(v[idx])!=nz.end())) continue;
            m[v[idx]-'a'] = i;
            vll a = solve(idx+1);
            m[v[idx]-'a'] = -1;
            if(a.size()>0){
                return a;
            }
        }
        return vll{};
    };

    vll ans = solve(0);
    if(ans.size()>0){
        cout << ans[0] << endl;
        cout << ans[1] << endl;
        cout << ans[2] << endl;
    }
    else cout << "UNSOLVABLE" << endl;
}
