#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N, K;
    cin >> N >> K;
    string s;
    cin >> s;
    int c = 1;
    int acc = 0;
    vector<int> r;

    for(int i=0; i<N; ++i){
        if(s[i]=='0'+c){
            ++acc;
            if(i==N-1) r.push_back(acc);
        }
        else{
            c = 1-c;
            r.push_back(acc);
            acc = 1;
        }
    }
    if(r.size()%2==0) r.push_back(0);

    if(K>=(r.size()-1)/2){
        int count = 0;
        for(auto e : r){
            count += e;
        }
        return 0;
    }

    int count = 0;
    for(int i=0; i<K; i++){
        count += r[i*2] + r[i*2+1];
    }
    count += r[2*K];

    int m = count;
    for(int i=0; 2*(i+K)<r.size()-2; ++i){
        count = count + r[2*(i+K)+1] + r[2*(i+K)+2] - r[2*i] - r[2*i+1];
        if(count>m) m = count;
    }
    cout << m << endl;
}
