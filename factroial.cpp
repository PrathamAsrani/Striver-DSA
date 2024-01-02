//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
private:
    vector<long long> ans;

public:
    Solution()
    {
        ans.push_back(1); // 0
        ans.push_back(2); // 1
    }
    vector<long long> factorialNumbers(long long N, int i = 1, int val = 2) // 2
    {
        // Write Your Code here1

        /*
        vector<long long> ans;
        int j = 2;
        ans.push_back(1);
        ans.push_back(2);
        for(int i = 0; i < N; i++){
            if(ans[i+1] >= N){
                break;
            }
            ans.push_back((ans[i]+ans[i+1])*j);
            j++;
        }
        if(N==2){
            return ans;
        }
        ans.pop_back();
        return ans;
        */

        if (this->ans[i] < N)
        {
            ans.push_back((this->ans[i] + this->ans[i - 1]) * val);
            factorialNumbers(N, ++i, ++val);
        }
        if (N == 2)
        {
            return ans;
        }
        ans.pop_back();
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long N;
        cin >> N;
        Solution ob;
        vector<long long> ans = ob.factorialNumbers(N);
        for (auto num : ans)
        {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends