#include <bits/stdc++.h>
using namespace std;

int helper(vector<int> &arr){
    vector<int> a = arr;
    sort(a.begin(), a.end());
    int ans = 0, n = arr.size();
    for(int i = 1; i < n; i++){
        if(arr[i] < arr[i-1]) {
            ans++;
            continue;
        }
        int idx = lower_bound(a.begin(), a.end(), arr[i-1]) - a.begin();
        if(a[idx+1] != arr[i]){
            ans++;
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {17, 13, 16, 19, 25, 23};
    cout << helper(arr) << "\n";
}