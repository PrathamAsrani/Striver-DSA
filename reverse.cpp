#include <bits/stdc++.h>

using namespace std;

int reverse (int a);
int reverseDigits (int a);

int main(){
    int a;
    cin >> a;
    cout << "Reversed of digits: " << reverse(a) << endl;
    cout << "Reversed of digits: " << reverseDigits(a) << endl;
}

int reverse (int a){
    string s = to_string(a);
    reverse(s.begin(), s.end()); // TC: O(n);
    return stoi(s);
}

int reverseDigits (int a){
    int ans = 0;
    while(a!=0){
        ans = ans*10 + a%10;
        a /= 10;
    }
    return ans;
}