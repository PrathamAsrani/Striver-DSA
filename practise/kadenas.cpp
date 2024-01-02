#include <bits/stdc++.h>

using namespace std;

long long int subArraySumsON(int a[], int n);
long long int subArraySumsON2(int a[], int n);
long long int subArraySumsON3(int a[], int n);

int main(){
    int arr[] = { 1, 2, 3 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "The elements by O(N): ";
    subArraySumsON(arr, n);
    cout << "\nThe elements by O(N2): ";
    subArraySumsON2(arr, n);
    cout << "\nhe elements by O(N3): ";
    subArraySumsON3(arr, n);
}

long long int subArraySumsON2(int a[], int n){
    // O(n2)
    vector<long long int> v;
    long long int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += a[j];
            v.push_back(sum);
        }
    }
    for (auto i : v) cout << i << " ";
}

long long int subArraySumsON3(int a[], int n){
    // O(n2)
    long long int sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            sum = 0;
            for (int k = i; k < j+1; k++)
            {
                sum += a[k];
            }
            cout << sum << " ";
        }
    }
}

long long int subArraySumsON(int a[], int n){
    long long sum = 0, maximum = a[0];
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        maximum = max(maximum,sum);
        cout << maximum << " ";
        if(sum < 0) sum = 0;
    }
    
}