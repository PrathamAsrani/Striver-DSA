// use to find the occureneces of string s in string t

#include <bits/stdc++.h>
using namespace std;

vector<int> KMP_Algorithm(string t, string s);
vector<int> prefix_function(string str);

int main()
{
    string t = "geeksforgeeks", s = "geek";
    vector<int> arr = KMP_Algorithm(t, s);
    for(auto idx:arr)
        cout << idx << " ";
    cout << "\n";
    return 0;
}

vector<int> KMP_Algorithm(string t, string s)
{
    vector<int> prefix = prefix_function(s), ans;
    int i(0), j(0);
    while(i < t.size()){
        if(t[i] == s[j])
            i++, j++;
        else{
            if(j != 0)
                j = prefix[j-1];
            else 
                i++;
        }
        if(j == s.size())
            ans.push_back(i-s.size()+1);
    }
    return ans;
}

vector<int> prefix_function(string str)
{
    // O(n^3)
    int n = str.size();
    vector<int> pi(n, 0);
    for(int i = 0; i < n; i++){
        for(int k = 0; k <= i; k++){
            if(str.substr(0, k) == str.substr(i-k+1, k))
                pi[i] = k;
        }
    }
    return pi;

    /*
    int n = str.size();
    vector<int> pi(n, 0);
    for(int i = 1; i < n; i++){
        int previously_matched_idx = pi[i-1];

        while(previously_matched_idx > 0 && str[i] != previously_matched_idx)
            previously_matched_idx = pi[previously_matched_idx-1];

        if(str[i] == str[previously_matched_idx])
            previously_matched_idx++;
        
        pi[i] = previously_matched_idx;
    }
    return pi;
    */
}