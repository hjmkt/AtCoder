#include <bits/stdc++.h>

using namespace std;

int main(){
    int N, K;
    cin >> N >> K;

    int count = 0;
    int r = 0;
    int last = 0;
    for(int i=0; i<N; ++i){
        int cur;
        cin >> cur;
        if(last<cur){
            ++r;
        }
        else{
            count += max(0, r-K+1);
            r = 1;
        }
        last = cur;
    }
    count += max(0, r-K+1);

    cout << count << endl;
}
