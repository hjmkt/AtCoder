#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    int N;
    string s;
    cin >> N >> s;

    int total = 0;
    for(int i=0; i<N; ++i){
        total += s[i]<='D'? (4 - (s[i]-'A')) : 0;
    }
    double avg = (double)total / (double)N;
    cout << setprecision(10) << avg << endl;
}
