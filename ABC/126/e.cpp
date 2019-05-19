#include <bits/stdc++.h>

using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    vector<int> p(N);
    for(int i=0; i<N; ++i){
        p[i] = i;
    }
    function<int(int)> root = [&](int x){
        if(p[x]==x) return x;
        return p[x] = root(p[x]);
    };
    for(int i=0; i<M; ++i){
        int x, y, z;
        cin >> x >> y >> z;
        int rx = root(x-1);
        int ry = root(y-1);
        if(rx==ry) continue;
        p[rx] = ry;
    }
    int count = 0;
    for(int i=0; i<N; ++i){
        if(p[i]==i) ++count;
    }
    cout << count << endl;
}
