#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    multiset<int> mset;
    mset.insert(1);
    mset.insert(1);
    mset.insert(4);
    mset.insert(5);
    mset.insert(5);

    for(auto i:mset) cout << i << " ";

    cout << "\n";

    multiset<int, greater<int>> ms;
    ms.insert(1);
    ms.insert(1);
    ms.insert(4);
    ms.insert(5);
    ms.insert(5);
    
    for(auto i:ms) cout << i << " ";
    
    return 0;
}
