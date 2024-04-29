#include <bits/stdc++.h>
using namespace std;

void helper(string s){
    stringstream ss(s);
    string word;
    int cnt = 0;
    while(getline(ss, word, ' ')){
        cout << word << "\n";
        cnt++;
    }
    cout <<"cnt: " << cnt << "\n";
}


int main(){
    string s = "n 1 2 3 4 5 6";

    helper(s);
}