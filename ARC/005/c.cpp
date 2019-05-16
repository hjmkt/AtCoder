#include <bits/stdc++.h>

using namespace std;

int main(){
    int H, W;
    cin >> H >> W;
    vector<string> c(H);
    int sx = 0, sy = 0;
    int gx = 0, gy = 0;
    for(int y=0; y<H; ++y){
        cin >> c[y];
        for(int x=0; x<W; ++x){
            if(c[y][x]=='s'){
                sx = x;
                sy = y;
            }
            else if(c[y][x]=='g'){
                gx = x;
                gy = y;
            }
        }
    }

    vector<vector<int>> d(H, vector<int>(W, INT_MAX));
    vector<vector<bool>> l(H, vector<bool>(W, false));
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> q; // dist, x, y
    q.push(tuple<int, int, int>(0, sx, sy));
    
    while(!q.empty()){
        auto p = q.top();
        q.pop();
        int x = get<1>(p);
        int y = get<2>(p);
        l[y][x] = true;
        int dist = get<0>(p);
        for(auto p : vector<pair<int, int>>{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}){
            int cx = x+p.first, cy = y+p.second;
            if(cx>=0 && cx<W && cy>=0 && cy<H && !l[cy][cx]){
                if(c[cy][cx]=='g') d[cy][cx] = min(d[cy][cx], dist+1);
                else if(c[cy][cx]=='.'){
                    if(dist+1<d[cy][cx]){
                        q.push(tuple<int, int, int>(dist+1, cx, cy));
                        d[cy][cx] = dist+1;
                    }
                }
                else if(c[cy][cx]=='#'){
                    if(dist+500*500<d[cy][cx]){
                        q.push(tuple<int, int, int>(dist+500*500, cx, cy));
                        d[cy][cx] = dist+500*500;
                    }
                }
            }
        }
    }
    if(d[gy][gx]<500*500*3) cout << "YES" << endl;
    else cout << "NO" << endl;
}
