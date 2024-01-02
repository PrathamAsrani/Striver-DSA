//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

/*
https://practice.geeksforgeeks.org/contest/gfg-weekly-coding-contest-132/problems
Problem 3: "Whether to check or not"

input: 
35 2
mjtsbltuab@23:53:19 lydeqkroj@23:53:36 wctwoadyo@23:53:59 wctwoadyo@23:54:11 kmeniehkbv@23:54:49 mjtsbltuab@23:55:47 lydeqkroj@23:56:36 wctwoadyo@23:56:45 mjtsbltuab@23:56:48 wctwoadyo@23:57:17 wctwoadyo@23:57:40 tzmb@23:57:46 kmeniehkbv@23:58:13 wctwoadyo@23:58:26 mjtsbltuab@23:59:06 lydeqkroj@23:59:57 mjtsbltuab@00:00:11 tzmb@00:00:56 lydeqkroj@00:01:37 lydeqkroj@00:01:53 tzmb@00:02:45 mjtsbltuab@00:02:46 mjtsbltuab@00:03:22 kmeniehkbv@00:03:37 mjtsbltuab@00:03:38 mjtsbltuab@00:04:07 wctwoadyo@00:04:13 mjtsbltuab@00:05:00 mjtsbltuab@00:05:55 tzmb@00:06:52 kmeniehkbv@00:07:05 wctwoadyo@00:07:46 lydeqkroj@00:08:29 wctwoadyo@00:09:13 lydeqkroj@00:09:20
*/


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
            cin >> A[i];
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i]<< " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Gfg {
  private:
    int cap;
    unordered_map<string, string> lastSub;
    
    int convertToSeconds(string &timeStamp){
        int hrs, mins, secs;
        sscanf(timeStamp.c_str(), "%d:%d:%d", &hrs, &mins, &secs);
        return ((hrs*3600) + (mins*60) + secs); 
    }
  public:
    Gfg(int cap){
        this->cap = cap;
    }
    bool judgeOrNot(string &submissionId) {
        stringstream ss(submissionId);
        string user, tStamp;
        getline(ss, user, '@');
        getline(ss, tStamp);
        
        auto it = lastSub.find(user);
        
        if(it == lastSub.end()){
            // user have not submitted before
            lastSub[user] = tStamp;
            return true;
        }
        
        string prev_tStamp = it->second;
        int prevTimeInSecs = convertToSeconds(prev_tStamp);
        int currTimeInSecs = convertToSeconds(tStamp);
        int timeDiff = currTimeInSecs - prevTimeInSecs;
        
        if(timeDiff < 0){
            currTimeInSecs += 86400;
            timeDiff = currTimeInSecs - prevTimeInSecs;
        }
        
        if(timeDiff >= this->cap){
            lastSub[user] = tStamp;
            return true;
        }
        
        return false;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        int gap;
        scanf("%d",&gap);
        
        
        vector<string> s(n);
        Array::input(s,n);
        
        Gfg obj(gap);
        for(int i=0;i<n;i++){
            bool res = obj.judgeOrNot(s[i]);
            if(res){
                cout<<"true ";
            }
            else{
                cout<<"false ";
            }
            
        }
        cout<<endl;
        
        
    }
}

// } Driver Code Ends