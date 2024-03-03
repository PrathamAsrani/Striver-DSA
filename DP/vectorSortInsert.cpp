#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    cout << "Hello world!\n";
    vector<int> arr;
    /*
    conditions: 
    1. array must contain atleast single number
    2. while using lower bound
    */
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(7);
    arr.push_back(8);

    // find position to push '4' in arr in logN
    cout << lower_bound(arr.begin(), arr.end(), 4) - arr.begin() << "\n";
    cout << upper_bound(arr.begin(), arr.end(), 4) - arr.begin() << "\n";
    return 0;
}
