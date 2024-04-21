#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
// quelink: https://www.geeksforgeeks.org/problems/inversion-of-array-1587115620/1

using namespace std;
using namespace __gnu_pbds;

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

/*
8
13 13 17 20 1 12 8 4
*/

int main(){
    ordered_set s;
    vector<int> arr = {2, 4, 1, 3, 5};
    int n = 5;
    // ans: 3
    int ans = 0;
    for(int i = n-1; i >= 0; i--){
        ans += (i != n-1) ? s.order_of_key({arr[i], i}) : 0;
        s.insert({arr[i], i});
    }
    cout << ans << "\n";
}
