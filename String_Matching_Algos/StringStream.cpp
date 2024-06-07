#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define ii ({ll a; cin >> a; a; })
#define si ({string string_input; cin >> string_input; string_input; })

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

void solve();

int main()
{
    string sentence = "the cattle was rattled by the battery";
    vector<string> arr;
    stringstream ss(sentence);
    string s;
    while (getline(ss, s, ' ')) arr.push_back(s);
    for(auto &str: arr) cout << str << " ";
    cout << "\n";
    return 0;
}
