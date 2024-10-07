/*
Example Problem : 
Given two integers a and b. Your task is to print the sum of 
all the digits appearing in the integers between a and b.
*/

#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

vector<int> getDigits(int a){
    vector<int> ans;
    while(a){
        ans.push_back(a%10);
        a /= 10;
    }
    return ans;
}

ll digitSum(int idx, ll sum, int tight, vector<int> &digits){
    if(idx == -1) return sum;
    if(dp[idx][sum][tight] != -1 && tight != -1){
        return dp[idx][sum][tight];
    }

    ll ret = 0;
    int k = tight == 1 ? digit[idx] : 9;
    for(int i = 0; i <= k; i++){
        int newTight = digit[idx] == i ? tight : 0;
        ret += digitSum(idx-1, sum+i, newTight, digits);
    }
    if(!tight){
        dp[idx][sum][tight] = ret;
    }
    return ret;
}

ll rangeSum(int a, int b){
    vector<int> digitA = getDigits(a);
    vector<int> digitB = getDigits(b);

    ll sum1 = digitSum(digitA.size()-1, 0, 1, digitA);
    ll sum2 = digitSum(digitB.size()-1, 0, 1, digitB);

    return abs(sum2 - sum1);
}

int main(){
    int a = 123, b = 1024;
    cout << rangeSum(a, b) << "\n";
}