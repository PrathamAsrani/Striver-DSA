#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> nums = {1, 1, 1, 2, 2, 2, 2, 3, 4, 5, 6, 7, 6, 5, 4, 3, 2};
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(),nums.end()),nums.end());
    for(auto i:nums)
        cout << i << " ";
    cout << "\n";
    priority_queue<int, vector<int>, greater<int>> pq;
    cout << pq.top() << "\n";
}
