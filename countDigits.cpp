#include <bits/stdc++.h>

using namespace std;

int countDigit (int a);
int countDigitBruteForce(int a);

int main(){
    int a;
    cin >> a;
    cout << "Number of digits: " << countDigit(a) << endl;
    cout << "Number of digits: " << countDigitBruteForce(a) << endl; // worst and basic
    cout << "Number of digits: " << floor(log10(a) + 1) << endl; // best approach TC = SC = O(1)
    cout << "Number of digits: " << ceil(log10(a)) << endl; // best approach TC = SC = O(1)
}

int countDigit (int a){
    // best approach TC = SC = O(1)
    return to_string(a).length();
}

int countDigitBruteForce(int a){
    int count = 0;
    while(a!=0){
        a/=10;
        count++ ;
    }
    return count;
}