#include <bits/stdc++.h>

using namespace std;

int main(){
    int C;
    cin >> C;
    int max_n = 0, max_m = 0, max_l = 0;
    for(int i=0; i<C; ++i){
        int nml[3];
        cin >> nml[0] >> nml[1] >> nml[2];
        sort(nml, nml+3);
        max_n = max(max_n, nml[0]);
        max_m = max(max_m, nml[1]);
        max_l = max(max_l, nml[2]);
    }
    cout << max_n*max_m*max_l << endl;
}
