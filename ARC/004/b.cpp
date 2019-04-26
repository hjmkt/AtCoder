#include <iostream>
#include <cmath>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <limits>

using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> ds(N, 0);
    for(int i=0; i<N; ++i){
        cin >> ds[i];
    }
    int minimum = numeric_limits<int>::max();
    int maximum = 0;

    for(int i=0; i<N; ++i){
        if(ds[i]>=minimum && ds[i]<=maximum) minimum = 0;
        else minimum = min(abs(minimum-ds[i]), abs(maximum-ds[i]));
        maximum = maximum + ds[i];
    }

    cout << maximum << endl;
    cout << minimum << endl;
}
