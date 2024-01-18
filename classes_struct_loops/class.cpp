#include <bits/stdc++.h>
using namespace std;

class Two
{
public:
    int key, value;
    Two() {}
    Two(int k)
    {
        key = k;
        value = 1;
    }
};

int main()
{
    Two *a = new Two();
    a->key = 1;
    a->value = 1;
    cout << a->key << " " << a->value << "\n";
}