// https://www.geeksforgeeks.org/problems/binary-subarray-with-sum/1

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    int numberOfSubarrays(vector<int>& arr, int n, int target){
        int ans = 0, cnt1 = 0;
        unordered_map<int, int> umpp;
        for(int i = 0; i < n; i++){
            if(arr[i]) 
                cnt1++;
            if(cnt1 == target)
                ans++;
            if(umpp.find(cnt1 - target) != umpp.end())
                ans += umpp[cnt1-target];
            umpp[cnt1]++;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int target; 
        cin >> target;
        vector<int> arr(N);
        for(int i=0; i<N; i++)
            cin >> arr[i];
        Solution obj;
        cout<<obj.numberOfSubarrays(arr, N, target)<<endl;
    }
    return 0;
}
// } Driver Code Ends