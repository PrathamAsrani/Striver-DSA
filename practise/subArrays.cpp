//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int countSubArrayProductLessThanK(const vector<int> &a, int n, long long k)
{
    // Naive Approach
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if ((a[i] * a[j]) < k)
            {
                cout << "c: " << c << " \na[i] * a[j]: " << a[i] * a[j] << "\n";
                c++;
            }
        }
    }
    return c-1;
}

int main(int argc, char const *argv[])
{
    vector<int> v{1, 9, 2, 8, 6, 4, 3};
    cout << countSubArrayProductLessThanK(v, 7, 100) << "\n";
    return 0;
}
