#include <bits/stdc++.h>

using namespace std;

int main(){
    int N, K;
    cin >> N >> K;
    vector<int> V(N);
    for(int i=0; i<N; ++i){
        cin >> V[i];
    }
    long long m = 0;
    for(int n=0; n<=K; ++n){
        for(int i=0; i<=n/2; ++i){
            int r = n - i;
            if(r>N) continue;
            for(int left=0; left<=r; ++left){
                vector<int> c;
                int right = r - left;
                for(int j=0; j<left; ++j) c.push_back(V[j]);
                for(int j=0; j<right; ++j) c.push_back(V[N-j-1]);
                sort(c.begin(), c.end(), [](auto x, auto y){ return x>y; });
                long long sum = 0;
                for(int k=0; k<r-i; ++k){
                    sum += c[k];
                }
                if(sum>m) m = sum;
            }
        }
    }
    cout << m << endl;
}
