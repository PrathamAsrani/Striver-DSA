#include <bits/stdc++.h>

using namespace std;

/*
for numbers exceeding value 10 raise to power 7 can't be hashed that's why we are using STL(map, unordered map), in java is collection(hash map)
*/

int main()
{
    /*
    // Integers
    int arr[] = {2, 1, 3, 4, 5, 6, 7, 8, 8};
    int hash[10] = {0};
    for (int i = 0; i < 9; i++)
    {
        hash[arr[i]] += 1;
    }
    for (int i = 0; i < 10; i++)
    {
        cout << i << " " << hash[i] << "\n";
    }
    */

    /*
    // Characters
    string s = "BBBAASSFFFF";
    int hash[26] = {0};
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    for(char i:s){
        hash[i - 'a'] += 1;
    }
    for(int i:hash){
        cout << i << " ";
    }
    */

    // All characters like @, #, etc...
    int hash[256] = {0}; // total are 256 characters (including all)
    string s = "Pratham@321";
    for(int i = 0; i < s.length(); i++){
        hash[s[i]] += 1;
    }

    int q;
    cin >> q;
    while(q--){
        char c;
        cin >> c;
        // fetch
        cout << hash[c] << endl;
    }
}