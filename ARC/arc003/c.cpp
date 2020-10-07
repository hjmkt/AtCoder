 #include <bits/stdc++.h>

using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    vector<string> c(N);
    int sx = 0, sy = 0;
    int gx = 0, gy = 0;
    for(int i=0; i<N; ++i){
        cin >> c[i];
        for(int j=0; j<M; ++j){
            if(c[i][j]=='s'){
                sx = j;
                sy = i;
            }
            else if(c[i][j]=='g'){
                gx = j;
                gy = i;
            }
        }
    }

    vector<vector<int>> tl(N, vector<int>(M));

    function<bool(int, int, double)> possible = [&](int y, int x, double ub){
        for(int i=0; i<N; ++i){
            for(int j=0; j<M; ++j){
                if(c[i][j]=='#') tl[i][j] = -1;
                else if(c[i][j]=='s') tl[i][j] = INT_MAX;
                else if(c[i][j]=='g') tl[i][j] = INT_MAX;
                else if(ub<=0) tl[i][j] = INT_MAX;
                else tl[i][j] = -log((double)(c[i][j]-'0') / ub) / log(0.99);
            }
        }
        vector<vector<bool>> det(N, vector<bool>(M, false));
        vector<vector<int>> dist(N, vector<int>(M, INT_MAX));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> p; // t, x, y
        p.push(make_tuple(0, sx, sy));
        while(p.size()>0){
            auto n = p.top();
            p.pop();
            int t = get<0>(n);
            int x = get<1>(n);
            int y = get<2>(n);
            det[y][x] = true;
            if(t<=dist[y][x] && t<=tl[y][x]){
                for(auto d : vector<pair<int, int>>{{-1, 0}, {0, -1}, {1, 0}, {0, 1}}){
                    int nx = x + d.first;
                    int ny = y + d.second;
                    if(nx>=0 && nx<M && ny>=0 && ny<N && !det[ny][nx]){
                        if(c[ny][nx]=='g') return true;
                        if(c[ny][nx]=='#') continue;
                        if(t+1<dist[ny][nx]){
                            dist[ny][nx] = t+1;
                            p.push(make_tuple(t+1, nx, ny));
                        }
                    }
                }
            }
        }
        return false;
    };

    double lb = 0.0;
    double ub = 9.0;
    while(ub-lb>5e-10){
        double mid = (lb+ub) / 2;
        if(possible(sy, sx, mid)) lb = mid;
        else ub = mid;
    }
    if(lb>0) cout << setprecision(12) << lb << endl;
    else if(possible(sy, sx, 0)) cout << 0 << endl;
    else cout << -1 << endl;
}
