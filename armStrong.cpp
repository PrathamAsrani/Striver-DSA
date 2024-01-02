//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

/*
Input: N = 153
Output: "Yes"
Explanation: 153 is an Armstrong number
since 1 + 125 + 27 = 153. // 1cube + 5cube + 3cube
Hence answer is "Yes".

Input: N = 1634
Output: "Yes"
Explanation: 1634 is an Armstrong number
since 1 + 1296 + 27 + 64 = 1634. // 1(power 4) + 6(power 4) + 3(power 4) + 4(power 4)
Hence answer is "Yes".
*/

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string armstrongNumber(int n){
        int val = n;
        vector <int> digitN;
        while(n != 0){
            digitN.push_back(n%10);
            n /= 10;
        }
        int ans = 0;
        for(auto i:digitN) ans += pow(i, ceil(log10(val)));
        return (ans == val)? "Yes": "No";
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.armstrongNumber(n) << " it's a armStrongNumber." << endl;
    }
    return 0;
}

// } Driver Code Ends