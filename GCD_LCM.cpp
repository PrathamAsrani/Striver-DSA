//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// brute force algorithm for GCD used, avg, best, and worst case TC: minimum number between a, and b;

// } Driver Code Ends
class Solution {
  public:
    vector<long long> lcmAndGcd(long long A , long long B) {
        // code here
        // cout << endl
        //      << A << " " << B 
        //      << endl;
        vector<long long> ans(2);
        ans[0] = lcm(A, B);
        ans[1] = gcd(A, B);
        return ans;
    }
    long long gcd(long long a, long long b);
    long long lcm(long long a, long long b);
};

long long Solution::lcm(long long a, long long b)
{
    return ((a * b)/gcd(a, b));
}

// long long Solution::gcd(long long a, long long b)
// {
//     // brute force algorithm for GCD used, avg, best, and worst case TC: minimum number between a, and b;
//     int gcd = 0;
//     if (a < b)
//     {
//         for (int i = 1; i <= a; i++)
//         {
//             if (a % i == 0 && b % i == 0)
//             {
//                 gcd = i;
//             }
//         }
//     }
//     else
//     {
//         for (int i = 1; i <= b; i++)
//         {
//             if (a % i == 0 && b % i == 0)
//             {
//                 gcd = i;
//             }
//         }
//     }
//     return gcd;
// }

// optimize algo for GCD: euclidean algorithm
/*
gcd(a, b) = gcd(a-b, b), where a>b
*/

long long Solution::gcd(long long a, long long b)
{
    while(a  > 0 && b > 0){
        if(a > b) a = a%b;
        else b = b%a;
    }
    return (a == 0) ? b:a;
}



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long A,B;
        
        cin>>A>>B;

        Solution ob;
        vector<long long> ans = ob.lcmAndGcd(A,B);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}
// } Driver Code Ends