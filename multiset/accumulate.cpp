#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    multiset<int> mset;
    mset.insert(1);
    mset.insert(2);
    mset.insert(3);
    mset.insert(4);
    mset.insert(5);

    int a = accumulate(mset.begin(), mset.end(), 0);
    auto it = mset.end();
    advance(it, -1);
    int b = accumulate(mset.begin(), it, 0);
    cout << a << "\n" << b << "\n";
    return 0;
}
