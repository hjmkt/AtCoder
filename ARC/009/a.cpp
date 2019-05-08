#include <bits/stdc++.h>

using namespace std;

int main(){
    int N;
    cin >> N;
    int total = 0;
    for(int i=0; i<N; ++i){
        int a, b;
        cin >> a >> b;
        total += a * b;
    }
    total = (int)((double)total * 1.05);
    cout << total << endl;;
}
