#include <bits/stdc++.h>

using namespace std;

int findSumO_1(int n){
    return n*(n+1)/2; // O(1)
}

int findSumBakwasAlgo(int n){
    int sum = 0;
    while(n > 0){
        sum += n;
        n--;
    }
    return sum;
}

int main(){
    int n = 6; // 6+5+4+3+2+1 = 21 | 6(6+1)/2 = 21
    int a;
    cin >> a;
    cout << "Best algo: " << findSumO_1(a) << endl; 
    cout << "\nWorst algo: " << findSumBakwasAlgo(a) << endl; 
}