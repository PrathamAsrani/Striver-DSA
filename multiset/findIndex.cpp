#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(5);

    cout << "in set: \t" << distance(s.begin(), s.lower_bound(5)) << "\n";
    
    multiset<int> mset;
    mset.insert(1);
    mset.insert(2);
    mset.insert(3);
    mset.insert(4);
    mset.insert(5);

    cout << "in multiset: \t" << distance(mset.begin(), mset.lower_bound(5)) << "\n";
    return 0;
}
