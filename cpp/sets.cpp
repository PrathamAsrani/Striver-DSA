#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    set<int> s{1, 2, 3};
    cout << *s.begin() << " " << *s.end() << "\n";
    for(auto i:s){
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}
