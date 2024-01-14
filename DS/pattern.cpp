#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int s = 1, e = n*n+1;
    vector<string> arr;
    for(int i = n; i >= 1; i--){
        string str;
        int j;
        for(j = s; j < i+s; j++)
            str += to_string(j) + '*';
        s = j;
        for(j = e; j < i+e; j++){
            str += to_string(j);
            if(j < i+e-1)
                str += '*';
        }
        e -= (i-1);
        arr.push_back(str);
    }
    for(int i = 0; i < arr.size(); i++){
        string s(i, '-');
        cout << s;
        cout << arr[i] << "\n";
    }
}