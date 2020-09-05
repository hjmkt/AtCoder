#include <bits/stdc++.h>

using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    vector<int> k(M);
    vector<int> p(M);
    vector<vector<int>> s(M);
    for(int i=0; i<M; ++i){
        cin >> k[i];
        s[i] = vector<int>(k[i]);
        for(int j=0; j<k[i]; ++j){
            cin >> s[i][j];
        }
    }
    for(int i=0; i<M; ++i){
        cin >> p[i];
    }
    long long count = 0;
    for(int i=0; i<(1<<N); ++i){
        bool valid = true;
        for(int j=0; j<M; ++j){
            int sum = 0;
            for(int l=0; l<k[j]; ++l){
                sum += (i>>(s[j][l]-1)) & 1;
            }
            if(sum%2!=p[j]){
                valid = false;
                break;
            }
        }
        if(valid) ++count;
    }
    cout << count << endl;
}
