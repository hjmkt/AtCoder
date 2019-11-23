#include <bits/stdc++.h>

using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    vector<pair<int, int>> BC(M);
    for(int i=0; i<N; ++i){
        cin >> A[i];
    }
    for(int i=0; i<M; ++i){
        cin >> BC[i].first >> BC[i].second;
    }
    sort(BC.begin(), BC.end(), [](auto l, auto r){
        return l.second>r.second;
    });
    sort(A.begin(), A.end(), [](auto l, auto r){
        return l<r;
    });
    int left = 0;
    for(int i=0; i<M; ++i){
        int count = 0;
        for(int j=left; j<N; ++j){
            if(A[j]<BC[i].second){
                A[j] = BC[i].second;
                ++left;
                ++count;
            }
            else break;
            if(count>=BC[i].first) break;
        }
    }
    long long s = 0;
    for(int i=0; i<N; ++i){
        s += A[i];
    }
    cout << s << endl;
}
