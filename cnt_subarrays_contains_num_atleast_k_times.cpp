// https://leetcode.com/contest/weekly-contest-375/problems/count-subarrays-where-max-element-appears-at-least-k-times/

#include <bits/stdc++.h>

using namespace std;

int countSubarrays(int *arr, int n, int num, int k);
int main(int argc, char const *argv[])
{
    int *arr = new int[5]{1, 2, 1, 5, 1};
    cout << "no. of arrays: " << countSubarrays(arr, 5, 1, 2) << "\n";
    return 0;
}

int countSubarrays(int *arr, int n, int num, int k){
    unordered_map<int, int> umpp;
    int s = 0, e = 0;
    int ans = 0;
    while(e < n){
        umpp[arr[e]]++;
        while(umpp[num] == k){
            ans += (n-e);
            umpp[arr[s]]--;
            s++;
        }
        e++;
    }
    return ans;
}