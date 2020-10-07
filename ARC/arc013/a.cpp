#include <bits/stdc++.h>

using namespace std;

int main(){
    int N, M, L;
    int P, Q, R;
    cin >> N >> M >> L;
    cin >> P >> Q >> R;
    int c0 = (N/P) * (M/Q) * (L/R);
    int c1 = (N/P) * (M/R) * (L/Q);
    int c2 = (N/Q) * (M/P) * (L/R);
    int c3 = (N/Q) * (M/R) * (L/P);
    int c4 = (N/R) * (M/P) * (L/Q);
    int c5 = (N/R) * (M/Q) * (L/P);
    cout << max({c0, c1, c2, c3, c4, c5}) << endl;
}
