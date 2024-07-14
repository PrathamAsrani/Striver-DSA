#include <iostream>
#include <vector>
using namespace std;

void rearrangeArray(vector<int> &arr, int x)
{
    int n = arr.size();
    int lessCount = 0, equalCount = 0, greaterCount = 0;

    // First pass: Count occurrences of less than, equal to, and greater than x
    for (int i = 0; i < n; ++i)
    {
        if (arr[i] < x)
        {
            lessCount++;
        }
        else if (arr[i] == x)
        {
            equalCount++;
        }
        else
        {
            greaterCount++;
        }
    }

    vector<int> less(lessCount), equal(equalCount), greater(greaterCount);
    int l = 0, e = 0, g = 0;

    // Second pass: Distribute elements into the respective vectors
    for (int i = 0; i < n; ++i)
    {
        if (arr[i] < x)
        {
            less[l++] = arr[i];
        }
        else if (arr[i] == x)
        {
            equal[e++] = arr[i];
        }
        else
        {
            greater[g++] = arr[i];
        }
    }

    // Third pass: Concatenate vectors back to the original array
    int index = 0;
    for (int i = 0; i < lessCount; ++i)
    {
        arr[index++] = less[i];
    }
    for (int i = 0; i < equalCount; ++i)
    {
        arr[index++] = equal[i];
    }
    for (int i = 0; i < greaterCount; ++i)
    {
        arr[index++] = greater[i];
    }
}

void f(vector<int> &arr, int x)
{
    int n = arr.size(), idx = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] < x){
            swap(arr[idx], arr[i]);
            idx++;
        }
    }

    for(int i = n-1; i >= idx; i--){
        if(arr[i] > x){
            for(int j = i; j > idx; j--){
                if(arr[j-1] < x){
                    swap(arr[j-1], arr[j]);
                }
            }
        }
    }
}

int main()
{
    // vector<int> arr = {5, 2, 8, 1, 6, 9, 4, 7, 3};
    vector<int> arr = {7, 8, 9, 10, 11, 12, 5, 5, 5, 1, 1, 2, 3, 4, 4, 4, 5, 5, 5};
    int x = 5;

    // approach 1: shift less values on left, and greater than equal to values on right in same order
    rearrangeArray(arr, x);
    for (int i = 0; i < arr.size(); ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    // output by approach one is 4 3 2 1 7 8 5 9 6

    // but we need:
    // expected output: 4, 3, 2, 1, 5, 9, 7, 8, 6
    f(arr, x);
    for (int i = 0; i < arr.size(); ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
