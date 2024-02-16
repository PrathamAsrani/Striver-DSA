#include<bits/stdc++.h>

using namespace std;
/*
long long power(long long x,
                long long y,
                const int& MOD)
{
    long long res = 1;
    while (y > 0) {
        if (y & 1)
            res = (res * x) % MOD;
        x = (x * x) % MOD;
        y /= 2;
    }
    return res;
}
 
*/

// find n^m in log(m)
int power(int n, int m){
    int mod = 1e9+7;
    long res = 1;
    while(m > 0){
        if(m & 1){
            res = (res * n) % mod; // if bits is set
        }
        m >>= 1; // divide by 2
        n = (n*n) % mod;
    }
    return (int)res;
}

int main(){
    int n, m; cin >> n >> m;

}