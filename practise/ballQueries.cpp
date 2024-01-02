#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        int count = 0;
        int n, q;
        cin >> n >> q;
        unordered_map<int, int> hashMap;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            hashMap[x]++; // stores freq.. of each ball
        }
        for (int i = 0; i < q; i++)
        {
            int k, x;
            cin >> k >> x;
            count = 0;
            if(k==1){
                for(auto itr:hashMap) if(itr.first < x) count += itr.second;
                cout << count << "\n";
            }else if(k==2){
                for(auto itr:hashMap) if(itr.first <= x) count += itr.second;
                cout << count << "\n";
            }else if(k==3){
                for(auto itr:hashMap) if(itr.first == x) count += itr.second;
                cout << count << "\n";
            }
        }
    }
    return 0;
}
