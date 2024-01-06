#include <bits/stdc++.h>

using namespace std;

void printPrimeFactors(int num);

int main(){
    /*
    input: 
    9 12
    */
    int n, m; cin >> n >> m;
    for(int i = n; i <= m; i++){
        cout << "Prime Factors of " << i << ": \t";
        printPrimeFactors(i);
    }
    return 0;
}

void printPrimeFactors(int num){
    // check for 2
    while(num%2 == 0)
        cout << 2 << " ", num /= 2;

    // case 2: check from 3 to num
    for(int i = 3; i <= sqrt(num); i+=2){
        while(num%i == 0)
            cout << i << " ", num /= i;
    }

    // case 3: number itself a prime number
    if(num > 2)
        cout << num << " ";
    cout << "\n";
}