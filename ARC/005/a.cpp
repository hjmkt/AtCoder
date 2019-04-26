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
    int count = 0;
    for(int i=0; i<N; ++i){
        string w;
        cin >> w;
        if(i==N-1) w = w.substr(0, w.length()-1);
        if(w=="TAKAHASHIKUN" || w=="Takahashikun" || w=="takahashikun"){
            ++count;
        }
    }
    cout << count << endl;
}
