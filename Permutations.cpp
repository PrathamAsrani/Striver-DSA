#include <bits/stdc++.h>

using namespace std;

void permute(vector<int> &a, int idx, vector<vector<int>> &ans);

int main(){
    int n;
    cin >> n;
    vector<vector<int>> ans;
    vector<int> a(n);
    for(int i = 1; i <= n; i++) a[i-1] = i;
    permute(a, 0, ans);
    for(auto arr:ans){
        for(auto itr:arr){
            cout << itr << " ";
        }
        cout << "\n";
    }
}

void permute(vector<int> &a, int idx, vector<vector<int>> &ans){
    if(idx == a.size()){
        ans.push_back(a);
        return ;
    }
    for(int i = idx; i < a.size(); i++){
        swap(a[i], a[idx]);
        permute(a, idx + 1, ans);
        swap(a[i], a[idx]); // backtracking
    }
}