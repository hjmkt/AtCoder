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

    ll T;
    cin >> T;
    rep(t, T){
        ll ax, ay, bx, by, cx, cy;
        cin >> ax >> ay >> bx >> by >> cx >> cy;
        //cout << ax << "," << ay << " " << bx << "," << by << " " << cx << "," << cy << endl;

        map<int, int> mx, my;
        ++mx[ax]; ++mx[bx]; ++mx[cx];
        ++my[ay]; ++my[by]; ++my[cy];
        ll px, py, qx, qy;
        for(auto p : mx){
            if(p.second==1) px = p.first;
            else qx = p.first;
        }
        for(auto p : my){
            if(p.second==1) py = p.first;
            else qy = p.first;
        }
        int r = 0;
        if(px<qx && py<qy) r = 0;
        else if(px>qx && py<qy) r = 1;
        else if(px>qx && py>qy) r = 2;
        else r = 3;
        //cout << "r=" << r << endl;

        ll total = LONG_MAX;
        if(r!=2){
            if(r==0){
                for(auto p : vector<pair<ll, ll>>{{1, 1}, {1, 0}, {0, 1}}){
                    ll dx = abs(qx-p.first);
                    ll dy = abs(qy-p.second);
                    ll md = min(dx, dy);
                    ll rd = max(dx-md, dy-md);
                    total = min(total, 2*md+2*rd+1);
                }
            }
            else if(r==1){
                for(auto p : vector<pair<ll, ll>>{{0, 0}, {0, 1}}){
                    ll dx = abs(qx-p.first);
                    ll dy = abs(qy-p.second);
                    ll md = min(dx, dy);
                    ll rd = max(dx-md, dy-md);
                    total = min(total, 2*md+2*rd+1);
                }
            }
            else if(r==3){
                for(auto p : vector<pair<ll, ll>>{{0, 0}, {1, 0}}){
                    ll dx = abs(qx-p.first);
                    ll dy = abs(qy-p.second);
                    ll md = min(dx, dy);
                    ll rd = max(dx-md, dy-md);
                    total = min(total, 2*md+2*rd+1);
                }
            }
        }
        else{
            ll dx = abs(qx);
            ll dy = abs(qy);
            ll md = min(dx, dy);
            ll rd = max(dx-md, dy-md);
            //cout << "dx: " << dx << ", dy:" << dy << endl;
            //cout << "md:" << md << ", rd:" << rd << endl;
            total = 2*md + 2*rd;
        }
        cout << total << endl;
    }
}
