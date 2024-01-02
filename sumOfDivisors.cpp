//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

/*
Given a positive integer N., The task is to find the value of sum(f[i], i=0 to n) where function F(i),
for the number i be defined as the sum of all divisors of ‘i‘.

Input:
N = 4
Output:
15
Explanation:
F(1) = 1
F(2) = 1 + 2 = 3
F(3) = 1 + 3 = 4
F(4) = 1 + 2 + 4 = 7
ans = F(1) + F(2) + F(3) + F(4)
    = 1 + 3 + 4 + 7
    = 15

Input:
N = 5
Output:
21
Explanation:
F(1) = 1
F(2) = 1 + 2 = 3
F(3) = 1 + 3 = 4
F(4) = 1 + 2 + 4 = 7
F(5) = 1 + 5 = 6
ans = F(1) + F(2) + F(3) + F(4) + F(5)
    = 1 + 3 + 4 + 7 + 6
    = 21

*/

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    long long sumOfDivisors(int N)
    {
        long long ans = 0;
        for(int i = 1; i <= N; i++)
            for(int j = 1; j <= i; j++) if(i%j == 0) ans += j;
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
        int N;
        cin>>N;
        Solution ob;
        long long ans  = ob.sumOfDivisors(N);
        cout<<ans<<endl;
    }
    return 0;
}
// } Driver Code Ends