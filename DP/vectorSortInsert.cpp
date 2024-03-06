#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    cout << "Hello world!\n";
    vector<int> arr;
    /*
    conditions: 
    1. array must contain atleast single number
    2. use either lower_bound or upper_bound and minus (-) with the arr.begin() ptr
    3. insert the in idx
    */
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(7);
    arr.push_back(8);

    int idx1 = lower_bound(arr.begin(), arr.end(), 4) - arr.begin();
    int idx2 = upper_bound(arr.begin(), arr.end(), 4) - arr.begin();

    // find position to push '4' in arr in logN
    cout << idx1 << "\n";
    cout << idx2 << "\n";

    arr.insert(arr.begin() + idx1, 4);
    arr.insert(arr.begin() + idx2, 4);

    for (auto i: arr) cout << i << " ";
    cout << "\n";
    return 0;
}
