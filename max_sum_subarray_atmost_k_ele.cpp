// https://practice.geeksforgeeks.org/contest/gfg-weekly-coding-contest-138/problems

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

typedef long long ll;

class Solution {
  public:
    ll kadanes_algo(int i, int j, vector<int> &arr){
        ll ans = LLONG_MIN, sum = 0;
        for(int idx = i; idx < j; idx++){
            sum += arr[idx];
            if(ans < sum)
                ans = sum;
            if(sum < 0)
                sum = 0;
        }
        return ans;
    }
    
    long long kMaxSubarray(int n, int k, vector<int> &arr) {
        
        ll ans = LLONG_MIN, sum = 0;
        for(int i = 0; i < n; i++){
            if(i+k < n)
                ans = max(ans, kadanes_algo(i, i+k, arr));
            else
                ans = max(ans, kadanes_algo(i, n, arr));
        }
        return ans;
        
        
        /*
        int i=0,j=0;
        ll maxi=INT_MIN;
        for(int i=0;i<n;i++){
            ll sum=0;
            for(int j=i;j<n;j++){
                sum+=arr[j];
                if(j-i+1<=k){
                    maxi=max(maxi,sum);
                }else{
                    break;
                }
            }
        }
        return maxi;
        */
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        int k;
        scanf("%d",&k);
        
        
        vector<int> arr(n);
        Array::input(arr,n);
        
        Solution obj;
        long long res = obj.kMaxSubarray(n, k, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends