#include <bits/stdc++.h>

using namespace std;

int main(){
    int N;
    cin >> N;
    vector<tuple<int, string, int>> s(N);
    for(int i=0; i<N; ++i){
        get<0>(s[i]) = i+1;
        cin >> get<1>(s[i]) >> get<2>(s[i]);
    }
    sort(s.begin(), s.end(), [](auto l, auto r){
        if(get<1>(l)<get<1>(r)) return true;
        else if(get<1>(l)==get<1>(r)) return get<2>(l)>get<2>(r);
        else return false;
    });
    for(int i=0; i<N; ++i){
        cout << get<0>(s[i]) << endl;
    }
}
