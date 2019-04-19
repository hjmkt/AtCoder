#include <iostream>
#include <vector>

using namespace std;

vector<string> split(string s, char d){
    vector<string> res;
    int last = 0;
    int pos = 0;
    while(pos<s.length()){
        if(s[pos]==d){
            res.push_back(s.substr(last, pos-last));
            last = pos+1;
        }
        ++pos;
    }
    res.push_back(s.substr(last, pos));
    return res;
}

string fmt(int n){
    return n<10? ("0" + to_string(n)) : to_string(n);
}

bool leap(int y){
    bool res = false;
    if(y%4==0) res = true;
    if(y%100==0) res = false;
    if(y%400==0) res = true;
    return res;
}

int main(){
    string buf;
    cin >> buf;
    auto ymd = split(buf, '/');
    int y = stoi(ymd[0]);
    int m = stoi(ymd[1][0]=='0'? ymd[1].substr(1) : ymd[1]);
    int d = stoi(ymd[2][0]=='0'? ymd[2].substr(1) : ymd[2]);
    if(y%m==0){
        int yy = y / m;
        if(yy%d==0){
            cout << y << "/" << fmt(m) << "/" << fmt(d) << endl;
            return 0;
        }
        int last = m==2? (leap(y)? 29 : 28) : (m==4||m==6||m==9||m==11)? 30 : 31;
        for(int i=d+1; i<=last; ++i){
            if(yy%i==0){
                cout << y << "/" << fmt(m) << "/" << fmt(i) << endl;
                return 0;
            }
        }
    }
    for(int i=m+1; i<=12; ++i){
        if(y%i==0){
            cout << y << "/" << fmt(i) << "/" << fmt(1) << endl;
            return 0;
        }
    }
    cout << (y+1) << "/" << fmt(1) << "/" << fmt(1) << endl;
}
