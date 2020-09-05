#include <bits/stdc++.h>

using namespace std;

int main(){
    int N;
    cin >> N;
    vector<vector<pair<long, long>>> e(N+1, vector<pair<long, long>>{}); // dest, weight
    for(int i=0; i<N-1; ++i){
        long u, v, w;
        cin >> u >> v >> w;
        e[u].push_back({v, w});
        e[v].push_back({u, w});
    }

    vector<int> c(N+1);
    int count = 0;
    function<void(int, int, int, int)> solve = [&](int current, int prev_node, int prev_color, int prev_dist){
        c[current] = (prev_color+prev_dist) % 2;
        ++count;
        if(count>=N) return;
        for(auto p : e[current]){
            if(p.first!=prev_node){
                solve(p.first, current, c[current], p.second);
            }
        }
    };
    solve(1, 0, 0, 0);
    for(int i=1; i<=N; ++i){
        cout << c[i] << endl;
    }
}
