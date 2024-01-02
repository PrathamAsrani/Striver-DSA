#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    string s = "Yo Yo Honey Singh";
    string sub = s.substr(3, s.size() - 3);
    cout << sub << "\n";

    string tmp = "I am a tmp str";
    string t = tmp.substr(5);
    cout << tmp << "\n" << t;
    return 0;
}
