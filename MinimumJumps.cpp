//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
    int minJumps(int arr[], int n){
        // Your code here
        int minJumps = 0;
        for(int i= 0; i < n; i = i){
            if(arr[i] >= n-i-1){
                minJumps++;                
                break;
            }
            else{
                i = findMax(arr, i);
                minJumps++;
            }
        }
        return minJumps;
    }
    int findMax(int arr[], int i);
};

int Solution::findMax(int arr[], int i){
    int max = arr[i]; 
    int index = i;
    for(int j = i+1; j <= i+arr[i]; j++){
        if(arr[j] > max){
            index = j;
            max = arr[j];
        }
    }
    return index;
}


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends