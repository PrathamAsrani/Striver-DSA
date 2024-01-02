//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int missingNumber(int a[], int n);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int i=0, n;
		cin>>n;
		int a[n+5];
		for(i=0;i<n-1;i++)
			cin>>a[i];
			
		cout<<missingNumber(a, n)<<endl;
	}
}
// } Driver Code Ends


int missingNumber(int arr[], int n)
{
    // Your code goes here
    int sum = 0;
    long val = 0;
    sum = (n*(n+1))/2;
	vector<int> v(arr, n+arr);
    for(int i = 0; i < n; i++) {
        val += arr[i];
    }
    return sum-val;
}