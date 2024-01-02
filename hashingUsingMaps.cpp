#include <bits/stdc++.h>

using namespace std;

int main(){
    // first preference
    // T.C. of map = logN (best, avg, worst case same)
    int arr[] = {8,7,6,5,4,2,3,4,6,7,8,9};
    map<int, int> hash;
    for(int i:arr) hash[i]++;
    int q;
    cin >> q;
    while(q--){
        int number;
        cin >> number;
        cout << hash[number] << endl;
    }

    char array[] = {'a', 'b', 'a'};
    map<char, int> hashChar;
    for(char c:array){
        hashChar[c]++;
    }

    // advantage of using unordered map (storing and fetching: O(1), worst case: O(n));
    unordered_map<int, int> bestHain;
}