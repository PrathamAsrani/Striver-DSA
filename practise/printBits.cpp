#include <bits/stdc++.h>
using namespace std;

void bin(unsigned n)
{
    if (n > 1)
        bin(n / 2);
 
    cout << n % 2;
}

int main(int argc, char const *argv[])
{
    string s;
    int num = 427;  
    bitset<32> bSet(num);
    while(num){
        char c = (num%2 == 0)? '0':'1';
        s.push_back(c);
        num /= 2;
    }
    cout << s << "\n";
    cout << s[0] - '0';
    bSet[2] = 1;
    cout << bSet.to_ullong();

    return 0;
}
