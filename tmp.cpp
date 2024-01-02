#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    list<vector<int>> li;
    unordered_map<int, list<vector<int>>::iterator> umpp;

    li.push_back({1, 2, 3});
    umpp[10] = li.begin();
    vector<int> &tmp = *(umpp[10]);
    cout << tmp[0] << "\n";

    // or
    cout << (*(umpp[10]))[0] << "\n";
    return 0;
}
