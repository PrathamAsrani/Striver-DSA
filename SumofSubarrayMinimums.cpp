// https://leetcode.com/problems/sum-of-subarray-minimums/description/?envType=daily-question&envId=2024-01-20

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*

// best solution try this in future

int mod=1e9+7;
int sumSubarrayMins(vector<int>& a) {
    int stackSum=a.front(),ans=a.front();
    stack<pair<int,int>> st;
    st.push({a.front(),1});
    for(int i=1;i<a.size();i++){
        pair<int,int> p={a[i],1};
        while(!st.empty() && st.top().first>=a[i]){
            auto [x,y]=st.top();
            stackSum-=x*y;
            p.second+=y;
            st.pop();
        }
        stackSum+=p.first*p.second;
        ans=(ans+0LL+stackSum)%mod;
        st.push(p);
    }
    return ans;
}
*/

ll sumSubarrayMins(vector<int> &arr);
int helper(int low, int high, int pos, vector<int> &arr, vector<pair<int, int>> &order, ll &ans);

int main()
{
    vector<int> arr = {3, 1, 2, 4};
    /*
    Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4].
    Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
    Sum is 17.
    */
    cout << "sum of minimums of each subarray: " << sumSubarrayMins(arr) << "\n";
    return 0;
}

ll sumSubarrayMins(vector<int> &arr)
{
    vector<pair<int, int>> order;
    for (int i = 0; i < arr.size(); i++)
        order.push_back({arr[i], i});
    sort(order.begin(), order.end());
    ll ans = 0;
    helper(0, arr.size() - 1, 0, arr, order, ans);
    return ans;
}

int helper(int low, int high, int pos, vector<int> &arr, vector<pair<int, int>> &order, ll &ans)
{
    int next_pos = order[pos].second;
    while (next_pos < low || next_pos > high)
        next_pos = order[++pos].second;

    // find number of subarrays in which arr[next_pos] is contributing
    ll left = next_pos - low + 1;
    ll right = high - next_pos + 1;

    ans += (left * right * arr[next_pos]);
    if (next_pos > low)
        helper(low, next_pos - 1, pos + 1, arr, order, ans);
    if (next_pos < high)
        helper(next_pos + 1, high, pos + 1, arr, order, ans);
}