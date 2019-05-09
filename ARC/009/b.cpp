#include <bits/stdc++.h>

using namespace std;

int main(){
    int b[10];
    int ib[10];
    for(int i=0; i<10; ++i){
        cin >> b[i];
        ib[b[i]] = i;
    }
    int N;
    cin >> N;
    vector<int> a(N);
    for(int i=0; i<N; ++i){
        cin >> a[i];
        string buf = to_string(a[i]);
        for(int j=0; j<buf.length(); ++j){
            buf[j] = ib[buf[j]-'0'] + '0';
        }
        a[i] = stoi(buf);
    }
    sort(a.begin(), a.end());
    for(int i=0; i<N; ++i){
        string buf = to_string(a[i]);
        for(int j=0; j<buf.length(); ++j){
            buf[j] = b[buf[j]-'0'] + '0';
        }
        a[i] = stoi(buf);
        cout << a[i] << endl;
    }
}
