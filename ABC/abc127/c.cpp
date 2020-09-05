#include <bits/stdc++.h>

using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    int left = 0;
    int right = N;
    for(int i=0; i<M; ++i){
        int l, r;
        cin >> l >> r;
        left = max(l, left);
        right = min(r, right);
    }
    if(left<=right) cout << (right-left+1) << endl;
    else cout << 0 << endl;
}
