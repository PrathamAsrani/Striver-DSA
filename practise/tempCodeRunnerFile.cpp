//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int countSubArrayProductLessThanK(const vector<int> &a, int n, long long k)
{
    // Naive Approach
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if ((a[i] * a[j]) < k)
            {
                cout << "c: " << c << " \na[i] * a[j]: " << a[i] * a[j] << "\n";
                c++;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    vector<int> v{1, 2,3, 4};
    countSubArrayProductLessThanK(v, 4, 10);
    return 0;
}
