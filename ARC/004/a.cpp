#include <iostream>
#include <map>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

double square(int x){
    return x*x;
}

int main(){
    int N;
    cin >> N;
    vector<pair<int, int>> ps(N, {0, 0});
    for(int i=0; i<N; ++i){
        cin >> ps[i].first >> ps[i].second;
    }
    double longest = 0;
    for(int i=0; i<N; ++i){
        for(int j=i; j<N; ++j){
            double l = square(ps[i].first-ps[j].first) + square(ps[i].second-ps[j].second);
            if(l>longest) longest = l;
        }
    }
    cout << setprecision(10) << sqrt(longest) << endl;
}
