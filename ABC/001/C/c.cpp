#include <iostream>
#include <vector>

using namespace std;

int main(){
    int deg, dis;
    cin >> deg >> dis;

    vector<string> dirs = {"N", "NNE", "NE", "ENE", "E", "ESE", "SE", "SSE", "S", "SSW", "SW", "WSW", "W", "WNW", "NW", "NNW"};
    deg *= 10;
    if(dis>14){
        int dir_idx = (deg+1125)%36000/2250;
        cout << dirs[dir_idx] << " ";
    }
    else {
        cout << "C" << " ";
    }

    if(dis<=14) cout << 0 << endl;
    else if(dis<=92) cout << 1 << endl;
    else if(dis<=200) cout << 2 << endl;
    else if(dis<=326) cout << 3 << endl;
    else if(dis<=476) cout << 4 << endl;
    else if(dis<=644) cout << 5 << endl;
    else if(dis<=830) cout << 6 << endl;
    else if(dis<=1028) cout << 7 << endl;
    else if(dis<=1244) cout << 8 << endl;
    else if(dis<=1466) cout << 9 << endl;
    else if(dis<=1706) cout << 10 << endl;
    else if(dis<=1958) cout << 11 << endl;
    else cout << 12 << endl;
}

