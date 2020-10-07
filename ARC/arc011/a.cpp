#include <bits/stdc++.h>

using namespace std;

int main(){
    int m, n, N;
    cin >> m >> n >> N;
    int total = N;
    while(N>=m){
        total += (N/m) * n;
        N = N%m + (N/m)*n;
    }
    cout << total << endl;
}
