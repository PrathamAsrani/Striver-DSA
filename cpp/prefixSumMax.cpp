//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

/*
// https://www.youtube.com/watch?v=JVyP8iP5i90&t=435s

Input: 
6
9 4 5 12 6 12
*/

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    void helper(int i, int arr[], int n, int &ans, int sum){
        if(i >= n){
            ans = max(ans, sum);
            return ;
        }
        helper(i+2, arr, n, ans, sum+arr[i]);
        helper(i+1, arr, n, ans, sum);
    }
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        /*
        int ans = 0;
        helper(0, arr, n, ans, 0);
        return ans;
        */
        
        int dp[n];
        dp[0] = arr[0];
        dp[1] = max(arr[0], arr[1]);
        for(int i = 2; i  <n; i++){
            dp[i] = max(dp[i-1], dp[i-2] + arr[i]);
        }
        return dp[n-1];
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends