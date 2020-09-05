#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int str_to_minutes(string s){
    int minutes = (int)(s[0]-'0')*10*60 + (int)(s[1]-'0')*60 + (int)(s[2]-'0')*10 + (int)(s[3]-'0');
    return minutes;
}

string minutes_to_str(int minutes){
    int hours = minutes / 60;
    minutes -= 60*hours;
    string str = (hours<10? ("0"+to_string(hours)) : to_string(hours)) + (minutes<10? ("0"+to_string(minutes)) : to_string(minutes));
    return str;
}

int main(){
    int N;
    cin >> N;
    vector<pair<int, int>> ds;
    for(int i=0; i<N; i++){
        string buf;
        cin >> buf;
        string start = buf.substr(0, 4);
        string end = buf.substr(5, 4);
        ds.push_back({str_to_minutes(start), str_to_minutes(end)});
    }
    sort(ds.begin(), ds.end());
    for(auto it = ds.begin(); it!=ds.end(); ++it){
        it->first = it->first / 5 * 5;
        it->second = (it->second+4) / 5 * 5;
    }
    pair<int, int> prev_ds = ds[0];
    vector<pair<int, int>> nds;
    for(int i=1; i<ds.size(); i++){
        if(prev_ds.second >= ds[i].first){
            prev_ds.second = max(prev_ds.second, ds[i].second);
        }
        else {
            nds.push_back(prev_ds);
            prev_ds = ds[i];
        }
    }
    nds.push_back(prev_ds);

    for(auto it = nds.begin(); it!=nds.end(); ++it){
        cout << minutes_to_str(it->first) << "-" << minutes_to_str(it->second) << endl;
    }
}

