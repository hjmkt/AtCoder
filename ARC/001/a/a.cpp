#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    string buf;
    cin >> buf;
    int count[4] = {};
    for(int i=0; i<n; i++){
        int c = (int)buf[i] - '1';
        count[c]++;
    }
    cout << max({count[0], count[1], count[2], count[3]}) << " " << min({count[0], count[1], count[2], count[3]}) << endl;
}
