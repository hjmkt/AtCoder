#include <bits/stdc++.h>

using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    vector<int> d(N);

    for(int i=0; i<N; ++i){
        d[i] = i+1;
    }
    int prev = 0, current = 0;
    for(int i=0; i<M; ++i){
        cin >> current;
        if(current==prev) continue;
        int idx = std::distance(d.begin(), find(d.begin(), d.end(), current));
        d[idx] = prev;
        prev = current;
    }
    for(int i=0; i<N; ++i){
        cout << d[i] << endl;
    }
}
