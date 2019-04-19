#include <iostream>
#include <vector>
 
using namespace std;
 
int main(){
    int N;
    cin >> N;
    vector<int> mountains(N);
    for(int i=0; i<N; ++i){
        cin >> mountains[i];
    }
    int highest = 0;
    int count = 0;
    for(auto m : mountains){
        if(m>=highest){
            ++count;
            highest = m;
        }
    }
    cout << count << endl;
}
