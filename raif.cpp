//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    bool isPrime(int num) {
        if (num <= 1) return false; 
        for (int i = 2; i * i <= num; i++) { 
            if (num % i == 0) return false; 
        }
        return true; 
    }

    int mostFrequentPrime(vector<vector<int>>& mat) {
        unordered_map<int, int> frequency; 

        int m = mat.size(), n = mat[0].size();
        

        
        vector<pair<int, int>> directions = {{0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};

        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (auto& dir : directions) {
                    int x = i, y = j;
                    int num = 0;
                    while (x >= 0 && x < m && y >= 0 && y < n) {
                        num = num * 10 + mat[x][y];
                        if (num > 10 && isPrime(num)) {
                            frequency[num]++;
                        }
                        x += dir.first;
                        y += dir.second;
                    }
                }
            }
        }

        int maxFreqPrime = -1;
        int maxFreq = 0;
        
        for (auto& [num, freq] : frequency) { // don't focus it will work
            if (freq > maxFreq || (freq == maxFreq && num > maxFreqPrime)) {
                maxFreq = freq;
                maxFreqPrime = num;
            }
        }

        return maxFreqPrime;
    }
};

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