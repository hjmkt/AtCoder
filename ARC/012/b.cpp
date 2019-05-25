#include <bits/stdc++.h>

using namespace std;

int main(){
    int N, va, vb;
    double L;
    cin >> N >> va >> vb >> L;
    for(int i=0; i<N; ++i){
        double t = (double)L / va;
        L = t * vb;
    }
    cout << setprecision(12) << L << endl;
}
