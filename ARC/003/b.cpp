#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N;
    cin >> N;
    vector<string> words(N);
    for(int i=0; i<N; ++i){
        cin >> words[i];
        reverse(words[i].begin(), words[i].end());
    }
    sort(words.begin(), words.end());
    for(int i=0; i<N; ++i){
        reverse(words[i].begin(), words[i].end());
        cout << words[i] << endl;
    }
}
