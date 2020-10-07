#include <bits/stdc++.h>

using namespace std;

int main(){
    int N;
    cin >> N;
    int n10 = N / 10;
    int n = N % 10;
    cout << (n10*100 + min(n*15, 100)) << endl;
}
