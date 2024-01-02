#include <bits/stdc++.h>

using namespace std;

int main(){
    vector<int> v = {1, 2, 3, 4, 5, 6};
    cout << *(v.begin()) << "\n";
    v.erase(v.begin()+1);
    for(auto i : v){
        cout << i << ' ';
    }
    cout << "\n" << *(v.begin());
    cout << "\nINdex of 5: " << (find(v.begin(), v.end(), 5) - v.begin());
    v.erase(v.begin() + (find(v.begin(), v.end(), 5) - v.begin()));
    cout << "\nAfter erasing element 5\n";
    for(auto i : v){
        cout << i << ' ';
    }
    cout << "\n" << *(v.end()) << "\n";
}