//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int nCr(int n, int r)
    {
        if (r > n)
            return 0;
        if (r == 0 || r == n)
            return 1;
        vector<int> dp(r + 1);
        dp[0] = 1;
        if (r > n - r)
            r = n - r;
        int mod = 1e9 + 7;
        for (int i = 1; i <= n; i++)
            for (int j = min(i, r); j > 0; j--)
                dp[j] = (dp[j] + dp[j - 1]) % mod;
        return dp[r];
    }

    /*
    auto ncr = [](ll n, ll r) -> ll {
        ll ans = 1;
        for(ll i = n; i > max(r, n-r); i--) ans *= i;
        ll den = 1;
        for(ll i = 1; i <= min(r, n-r); i++) den *= i;
        ans /= den;
        return ans;
    };
    */

    long long ncr(int n, int r)
    {
        // most optimized
        long long p = 1, k = 1;
        if (n - r < r)
            r = n - r;
        if (r != 0)
        {
            while (r)
            {
                p *= n;
                k *= r;
                long long m = __gcd(p, k);
                p /= m;
                k /= m;
                n--;
                r--;
            }
        }
        else
            p = 1;
        return p;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, r;
        cin >> n >> r;

        Solution ob;
        cout << ob.nCr(n, r) << endl;
    }
    return 0;
}
// } Driver Code Ends