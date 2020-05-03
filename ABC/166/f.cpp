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

    ll N, A, B, C;
    cin >> N >> A >> B >> C;
    vector<string> s(N);
    rep(i, N) cin >> s[i];

    vector<char> a;
    rep(i, N){
        if(s[i]=="AB"){
            if(A>B || A>=2){
                --A, ++B;
                a.push_back('B');
            }
            else if(A<B){
                ++A, --B;
                a.push_back('A');
            }
            else if(A==0){
                cout << "No" << endl;
                return 0;
            }
            else if(i==N-1) a.push_back('A');
            else{
                string next = s[i+1];
                if(next=="AC" || next=="AB"){
                    ++A, --B;
                    a.push_back('A');
                }
                else{
                    --A, ++B;
                    a.push_back('B');
                }
            }
        }
        else if(s[i]=="BC"){
            if(B>C || B>=2){
                --B, ++C;
                a.push_back('C');
            }
            else if(B<C){
                ++B, --C;
                a.push_back('B');
            }
            else if(B==0){
                cout << "No" << endl;
                return 0;
            }
            else if(i==N-1) a.push_back('B');
            else{
                string next = s[i+1];
                if(next=="AB" || next=="BC"){
                    ++B, --C;
                    a.push_back('B');
                }
                else{
                    --B, ++C;
                    a.push_back('C');
                }
            }
        }
        else {
            if(A>C || A>=2){
                --A, ++C;
                a.push_back('C');
            }
            else if(A<C){
                ++A, --C;
                a.push_back('A');
            }
            else if(A==0){
                cout << "No" << endl;
                return 0;
            }
            else if(i==N-1) a.push_back('A');
            else{
                string next = s[i+1];
                if(next=="AB" || next=="AC"){
                    ++A, --C;
                    a.push_back('A');
                }
                else{
                    --A, ++C;
                    a.push_back('C');
                }
            }
        }
    }
    cout << "Yes" << endl;
    rep(i, N){
        cout << a[i] << endl;
    }
}
