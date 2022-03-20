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

    ll N;
    cin >> N;
    string T;
    cin >> T;
    ll dx = 1, dy = 0;
    ll cx = 0, cy = 0;
    for(char c: T){
        if(c=='S'){
            cx += dx;
            cy += dy;
        }
        else{
            if(dx==0){
                if(dy==1){
                    dx = 1;
                    dy = 0;
                }
                else{
                    dx = -1;
                    dy = 0;
                }
            }
            else if(dx==1){
                dx = 0;
                dy = -1;
            }
            else{
                dx = 0;
                dy = 1;
            }
        }
    }
    cout << cx << " " << cy << endl;
}
