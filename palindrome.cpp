//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
	public:
		string is_palindrome(int n)
		{
		    string s = to_string(n);
            int count = 0;
            for (int i = 0; i < (s.length()) / 2; i++)
            {
                if (s[i] == s[(s.length()) - i - 1])
                {
                    count++;
                }
            }
            if (count == s.length() / 2)
                return "Yes";
            return "No";
		}

        string palindrome(int n);
};

string Solution:: palindrome(int n){
    string s = to_string(n);
    reverse(s.begin(), s.end());
    return s;
}

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n;
    	cin >> n;
    	Solution ob;
    	string ans = ob.is_palindrome(n);
    	cout << ans <<"\n";
    }
	return 0;
}

// } Driver Code Ends