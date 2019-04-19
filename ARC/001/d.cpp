#include <iostream>
#include <list>
#include <map>
#include <limits>

using namespace std;

int main(){
    int N;
    cin >> N;
    int s, g;
    cin >> s >> g;
    list<pair<int, int>> left_path; // y, x
    list<pair<int, int>> right_path; // y, x
    for(int i=0; i<=N; i++){
        int left, right;
        cin >> left >> right;
        left_path.push_back({i, left});
        right_path.push_back({i, right});
    }

    double prev_left_grad = numeric_limits<double>::min();
    double prev_right_grad = numeric_limits<double>::max();
    double left_checkpoint = left_path.begin();
    double right_checkpoint = right_path.begin();
    double dist = 0;
    for(auto itl = left_path.begin()+1, itr = right_path.begin()+1; itl != left_path.end(); ++itl, ++itr){
        double  left_grad = (itl->second-(itl-1)->second) / (itl->first-(itl-1)->first)
        double  right_grad = (itr->second-(itr-1)->second) / (itr->first-(itr-1)->first)
        for(auto itll = itl-1; itll-1 != left_checkpoint; --itll){
            
        }
    }
}
