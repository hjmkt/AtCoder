#include <iostream>
#include <cmath>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> p(N+1, 1);
    for(int i=2; i<=N; ++i){
        if(p[i]>0){
            for(int j=i+i; j<=N; j+=i){
                p[j] = 0;
            }
        }
    }
    if(p[N]>0) cout << "YES" << endl;
    else cout << "NO" << endl;
}
