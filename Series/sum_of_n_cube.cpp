#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define ii ({ll a; cin >> a; a;})
#define si ({string string_input; cin >> string_input; string_input;})
#define vll vector<ll>
#define vi vector<int>
#define vvi vector<vector<int>>
#define pb push_back

ll mod = 1e9+7;
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a%b); }
ll lcm(ll a, ll b) { return a/gcd(a, b) * b; }

template <typename T>
void dis(vector<T> &v) { for(auto &i: v) cout << i << " "; cout << "\n"; } 
template <typename T, size_t N>
void show(T (&arr)[N]) { for(int i = 0; i < N; i++) cout << arr[i] << " "; cout << "\n"; }

int main()
{
    cout << "Enter n: ";
    ll n = ii;
    cout << "cummulative sum of n cube is " << n*n*(n+1)*(n+1)/4 << "\n";
}

