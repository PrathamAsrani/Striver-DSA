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
    int n = arr.size(), k = 2;
    ll finalAns = LLONG_MIN;

    for (int itr = 0; itr <= n - k; itr++)
    {
        ll mini, maxi, ans;
        mini = maxi = ans = arr[itr];

        for (int i = itr + 1; i < itr + k; i++)
        {
            ll tmp = max({(ll)arr[i], arr[i] * mini, arr[i] * maxi});
            mini = min({(ll)arr[i], arr[i] * mini, arr[i] * maxi});
            maxi = tmp;
            ans = max(ans, maxi);
        }

        finalAns = max(finalAns, ans);
    }
    cout << finalAns << "\n";
}
