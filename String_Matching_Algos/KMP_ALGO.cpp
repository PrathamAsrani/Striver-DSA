//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        vector<int> Prefix_function(string str){
            /*
            // O(n^3)
            int n = str.size();
            vector<int> pi(n);
            for(int i = 0; i < n; i++){
                for(int k = 0; k <= i; k++){
                    if(str.substr(0, k) == str.substr(i-k+1, k))
                        pi[i] = k;
                }
            }
            return pi;
            */
            
            
            // O(n)
            int n = str.size();
            vector<int> pi(n, 0);
            for(int i = 1; i < n; i++){
                int prev_match_idx = pi[i-1];
                
                while(prev_match_idx > 0 && str[i] != str[prev_match_idx])
                    prev_match_idx = pi[prev_match_idx-1];
                
                if(str[i] == str[prev_match_idx])
                    prev_match_idx++;
                
                pi[i] = prev_match_idx;
            }
            return pi;
        }
        
        vector<int> KMP_algo(string t, string s){
            vector<int> ans, prefix = Prefix_function(s);
            int i = 0, j = 0;
            while(i < t.size()){
                if(t[i] == s[j])
                    i++, j++;
                else{
                    if(j!=0)
                        j = prefix[j-1];
                    else 
                        i++;
                }
                if(j == s.size())
                    ans.push_back(i-s.size()+1);
            }
            return ans;
        }
        
        vector<int> search(string pat, string txt)
        {
            /*
            vector<int> ans;
            int m = pat.size(), n = txt.size();
            if(m > n)
                return ans;
            char start = pat[0];
            for(int i = 0; i < n; i++){
                if(txt[i] == start){
                    string tmp;
                    if(i+m <= n) 
                        tmp = txt.substr(i, m);
                    if(tmp == pat) 
                        ans.push_back(i+1);
                }
            }
            return ans;
            */
            
            return KMP_algo(txt, pat);
        }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        if (res.size()==0)
            cout<<-1<<endl;
        else {
            for (int i : res) cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends