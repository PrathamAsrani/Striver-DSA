//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

string reverseStr(string s);

class Solution {
  public:
    long long reversedBits(long long X) {
        // using a bitset
        bitset<32> bitS1(X);// converts number into a binary 
        string s =  bitS1.to_string(); // converts biset object into string
        reverse(s.begin(), s.end()); // reverse the string
        bitset<32> bitS2(s); // create another bitset for the reversed string
        return bitS2.to_ullong(); // to_ullong() --> converts string number into binary then binary to decimal
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long X;
        
        cin>>X;

        Solution ob;
        cout << ob.reversedBits(X) << endl;
    }
    return 0;
}
// } Driver Code Ends