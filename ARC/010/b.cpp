#include <bits/stdc++.h>

using namespace std;

vector<string> split(const string &s, char delim){
    vector<string> elems;
    stringstream ss(s);
    string buf;
    while(getline(ss, buf, delim)){
        if(!buf.empty()) elems.push_back(buf);
    }
    return elems;
}

int main(){
    int N;
    cin >> N;
    vector<pair<int, int>> hd(N);
    for(int i=0; i<N; ++i){
        string line;
        cin >> line;
        auto md = split(line, '/');
        hd.push_back({stoi(md[0]), stoi(md[1])});
    }
    int max_hds = 0;
    int hds = 0;
    int comp_hds = 0;
    int m = 1, d = 1;
    int h = (d + 26*(13+1)/10 + 2011%100 + 2011%100/4 + -2*(2011/100)+2011/100/4) % 7; // 0..6: Sat..Fri
    for(int i=1; i<=366; ++i){
        if(find(hd.begin(), hd.end(), make_pair(m, d)) != hd.end()) ++comp_hds;

        if(h>=2){
            if(comp_hds>0){
                --comp_hds;
                ++hds;
            }
            else{
                if(hds>max_hds) max_hds = hds;
                hds = 0;
            }
        }
        else{
            ++hds;
        }

        if(m==2 && d==29){
            ++m;
            d = 1;
        }
        else if((m==4||m==6||m==9||m==11) && d==30){
            ++m;
            d = 1;
        }
        else if((m==1||m==3||m==5||m==7||m==8||m==10||m==12) && d==31){
            ++m;
            d = 1;
        }
        else{
            ++d;
        }
        h = (h+1) % 7;
    }
    if(hds>max_hds) max_hds = hds;

    cout << max_hds << endl;
}
