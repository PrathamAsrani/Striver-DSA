#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> v = { 1, 45, 54, 71, 76, 17 };

    cout << (find(v.begin(), v.end(), 1) != v.end()) ? "true" : "false";
    cout << "\n";
    cout << count(v.begin(), v.end(), 1);
    return 0;
}
