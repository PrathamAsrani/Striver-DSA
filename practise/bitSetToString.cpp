//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution{
    public:
    int setSetBit(int x, int y, int l, int r){
        // code here
        bitset<32> _x(x);
        bitset<32> _y(y);
        string __x = _x.to_string();
        string __y = _y.to_string();
        __x.erase(0, __x.find('1'));
        __y.erase(0, __y.find('1'));
        cout << __x << ": " << __x.length() << " \n" << __y << ": "<< __y.length() << "\n";
        
    }    
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int x, y, l, r;
        cin>>x>>y>>l>>r;
        
        Solution ob;
        cout<<ob.setSetBit(x, y, l, r)<<"\n";
    }
    return 0;
}
// } Driver Code Ends