#include <bits/stdc++.h>

using namespace std;
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);

int main(int argc, char const *argv[])
{
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {3, 4};
    cout << findMedianSortedArrays(nums1, nums2) << endl;
    return 0;
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n1 = nums1.size(), n2 = nums2.size();
    int n = n1+n2;
    int c1 = n/2;
    int c2 = c1-1;
    int i = 0, j =0, cnt = 0;
    double val1 = -1, val2 = -1;
    while(i < n1 && j < n2){
        if(nums1[i] < nums2[j]){
            if(cnt == c1) val1 = nums1[i];
            if(cnt == c2) val2 = nums1[i];
            cnt++, i++;
        }else{
            if(cnt == c1) val1 = nums2[j];
            if(cnt == c2) val2 = nums2[j];
            cnt++, j++;
        }
    }
    while(i < n1){
        if(cnt == c1) val1 = nums1[i];
        if(cnt == c2) val2 = nums1[i];
        cnt++, i++;
    }
    while(j < n2){
        if(cnt == c1) val1 = nums2[j];
        if(cnt == c2) val2 = nums2[j];
        cnt++, j++;
    }
    return (n%2)? val1:(val1+val2)/2;
}