/*
References: 
https://www.geeksforgeeks.org/introduction-to-segment-trees-data-structure-and-algorithm-tutorials/ : for construction of segment tree
https://www.geeksforgeeks.org/segment-tree-sum-of-given-range/ : for size of segment tree
*/


/*
query: get sum in range from left to right in LOG(N) time
Update: Given an index, idx, update the value of the array at index idx with value V, and recalculate sum in ranges LOG(N) time
*/


#include <bits/stdc++.h>
using namespace std;

#define empty 0

class SegmentTree
{
private:
    vector<int> arr;
    vector<int> segment_tree;

    void build(int node, int low, int high){
        if(low == high)
            segment_tree[node] = arr[low];
        else{
            int mid = low+(high-low)/2;
            build(2*node+1, low, mid);
            build(2*node+2, mid+1, high);
            segment_tree[node] = segment_tree[2*node+1] + segment_tree[2*node+2];
        }
    }

    long long query(int root, int TreeLeft, int TreeRight, int left, int right){
        // out of range
        if(TreeLeft > right || TreeRight < left)
            return 0;

        // range found that contains left and right
        if(TreeLeft >= left && TreeRight <= right)
            return segment_tree[root];

        // go to child nodes
        int TreeMid = (TreeLeft + TreeRight) / 2;
        return query(2 * root + 1, TreeLeft, TreeMid, left, right) + query(2 * root + 2, TreeMid + 1, TreeRight, left, right);
    }

    void UpdateValue(int root, int TreeLeft, int TreeRight, int idx, int new_value){
        if(TreeLeft == TreeRight){
            arr[idx] = new_value;
            segment_tree[root] = new_value;
        }else{
            int TreeMid = TreeLeft + (TreeRight-TreeLeft)/2;
            if(TreeLeft <= idx && idx <= TreeMid)
                UpdateValue(2*root+1, TreeLeft, TreeMid, idx, new_value);
            else
                UpdateValue(2*root+2, TreeMid+1, TreeRight, idx, new_value);
            
            // backtrack
            segment_tree[root] = segment_tree[2*root+1] + segment_tree[2*root+2];
        }
    }

public:
    SegmentTree(vector<int> arr){
        this->arr = arr;
        // calculate maxsize of segment tree: (2 * 2^⌈log2n⌉  – 1).
        int x = (int)(ceil(log2(arr.size()))); // height of tree
        segment_tree.resize(2*(int)pow(2, x)-1);
        this->build(0, 0, arr.size()-1);
    }

    SegmentTree(int arr[], int n){
        for(int i = 0; i < n; i++)
            this->arr.push_back(arr[i]);
        // calculate maxsize of segment tree: (2 * 2^⌈log2n⌉  – 1).
        int x = (int)(ceil(log2(this->arr.size()))); // height of tree
        segment_tree.resize(2*(int)pow(2, x)-1, empty);
        this->build(0, 0, this->arr.size()-1);
    }

    void display(){
        cout << "arr: \n";
        for(auto i:arr)
            cout << i << " ";
        cout << "\nSegment Tree: \n";
        for(auto i:segment_tree)
            if(i != empty) cout << i << " ";
        cout << "\n";
    }

    long long getSumInRange(int left, int right){
        return query(0, 0, this->arr.size()-1, left, right);
    }

    void UpdateIdxValue(int idx, int value){
        UpdateValue(0, 0, this->arr.size()-1, idx, value);
    }
};


int main(){
    int array[] = { 0, 1, 3, 5, -2, 3 };
    int n = sizeof(array)/sizeof(array[0]);
    SegmentTree s_tree(array, n);
    s_tree.display();
    cout << "sum in range 0 to 3: " << s_tree.getSumInRange(0, 3) << "\n";
    cout << "sum in range 0 to n-1: " << s_tree.getSumInRange(0, n-1) << "\n";

    s_tree.UpdateIdxValue(0, 100);
    s_tree.display();
}
