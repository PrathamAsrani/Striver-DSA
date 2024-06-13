#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define ii ({ll a; cin >> a; a; })
#define si ({string string_input; cin >> string_input; string_input; })

template <typename T>
void dis(vector<T> &v)
{
    for (auto &i : v)
        cout << i << " ";
    cout << "\n";
}
template <typename T, size_t N>
void show(T (&arr)[N])
{
    for (int i = 0; i < N; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

int main()
{
    vector<int> arr = {6, -3, -10, 0, 2};
    int n = arr.size();
    ll mini, maxi, ans;
    mini = maxi = ans = arr[0];
    for (int i = 1; i < n; i++)
    {
        ll tmp = max({(ll)arr[i], arr[i] * mini, arr[i] * maxi});
        mini = min({(ll)arr[i], arr[i] * mini, arr[i] * maxi});
        maxi = tmp;
        ans = max(ans, maxi);
    }
    cout << ans << "\n";
}
